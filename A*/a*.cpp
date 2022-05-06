#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::endl;
using std::sort;

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kEnd};
// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

///////////////////////////////////////////////////////////////////////////////
// Reading Board file
///////////////////////////////////////////////////////////////////////////////
vector<State> ParseLine(string line)
{
    istringstream lineStream(line);

    char c;
    int n;
    vector<State> row;
    while (lineStream >> n >> c)
    {
        //row.push_back(n);
        if (n == 1)
            row.push_back(State::kObstacle);
        else 
            row.push_back(State::kEmpty);
    }
    return row; 
}


vector<vector<State>> ReadBoardFile(string path)
{
    vector<vector<State>> board;
    std::ifstream myFile;

    std::cout << "File = " << path << endl << endl;

    myFile.open(path, ifstream::in);

    if (myFile)
    {
        //std::cout << "The file stream has been created!\n";
        std::string line;
        while (getline(myFile, line))
        {
            //std::cout << line << "\n";
            board.push_back(ParseLine(line));
        }
    }
    else
    {
        std::cout << "Unable to open the file. error = " << myFile.fail() << endl;
    }
    
    myFile.close();
    return board;
}
///////////////////////////////////////////////////////////////////////////////
// A* algorithm 
///////////////////////////////////////////////////////////////////////////////

/**
 * Returns true if F value of node 1 is greater than node 2
 * f = g + h
 */
bool Compare(const vector<int> node1, const vector<int> node2)
{
    return ((node1[2] + node1[3]) > (node2[2] + node2[3]));
}
/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}

/**
 * return true, if cell is valid
 */
bool CheckValidCell(int x, int y, vector<vector<State>> &board)
{
    //if x and y are on the grid
    if ((x >= 0 && x < board.size()) && (y >= 0 && y < board[0].size()))
    {
        return (board[x][y] == State::kEmpty);
    }
    return false;
}

int Heuristic(int x1, int y1, int x2, int y2)
{
    return (abs(x2 - x1) + abs(y2 - y1));
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openNodes,
               vector<vector<State>> &board)
{
    vector<int> node = {x, y, g, h};
    openNodes.push_back(node);

    board[x][y] = State::kClosed;
}

void ExpandNeighbors(const vector<int> &currentNode, vector<vector<int>> &openNodes,
                     vector<vector<State>> &board, int end[2])
{
    int x = currentNode[0];
    int y = currentNode[1];
    int g = currentNode[2];

    for (int i = 0; i < 4; i++)
    {
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        if (CheckValidCell(x2, y2, board))
        {
            int g2 = g + 1;
            int h2 = Heuristic(x2, y2,end[0], end[1]);
            AddToOpen(x2, y2, g2, h2, openNodes, board);
        }
    }
}
/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> &board, const int start[2], int end[2])
{
    vector<vector<int>> openNodes{};
    int x = start[0];
    int y = start[1];
    int g = 0;
    int h = Heuristic(x, y, end[0], end[1]);
    AddToOpen(x, y, g, h, openNodes, board);

    /**
     * Keep looping till openNode list is empty. 
     * Therefore, the open node list size must be reduced at every iteration? 
     */
    while (openNodes.size() > 0)
    {
        CellSort(&openNodes);

        auto currentNode = openNodes.back();
        openNodes.pop_back();
        x = currentNode[0];
        y = currentNode[1];

        board[x][y] = State::kPath;
        // Check if we're done.,
        if (x == end[0] && y == end[1])
        {
            board[start[0]][start[1]] = State::kStart;
            board[end[0]][end[1]] = State::kEnd;
            return board;
        }
        else
            ExpandNeighbors(currentNode, openNodes, board, end);
    }
    return board;
}

string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "x ";
    case State::kPath:
        return "c ";
    case State::kStart:
        return "s ";
    case State::kEnd:
        return "e ";
    default:
        return ". ";
    }
}
void PrintBoard(const vector<vector<State>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << "\t";
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << CellString(board[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<State>> board, solution;

    int start[2] = {0, 0};
    int end[2] = {4, 5};

    board = ReadBoardFile("/home/swapnil/Documents/cpp/A*/files/1.board");
    cout << "Input Board : " << endl
         << endl;
    PrintBoard(board);

    solution = Search(board, start, end);
    cout << "A* Solution : " << endl
         << endl;
    PrintBoard(board);

    return 0;
}