#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::endl;

enum class State {kEmpty, kObstacle};

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
int Heuristic(int x1, int y1, int x2, int y2)
{
    return (abs(x2 - x1) + abs(y2 - y1));
}
vector<vector<State>> Search(const vector<vector<State>> board, const int start[2], const int end[2])
{
    vector<vector<State>> solution = {};

    return solution;
}

string CellString(State cell)
{
    switch(cell)
    {
        case State::kObstacle:
            return "⛰️   ";
            default:
            return "0   ";
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
    solution = Search(board, start, end);
    cout << "Input Board : " << endl << endl;
    PrintBoard(board);

    cout << endl;
    cout << "A* Solution : " << endl << endl;
    PrintBoard(board);

    return 0;
}