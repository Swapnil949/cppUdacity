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

enum class State {kEmpty, kObstacle};


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

    std::cout << "File = " << path << "\n";

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
        std::cout << "Unable to open the file. error = " << myFile.fail() << "\n";
    }

    myFile.close();
    return board;
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
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<State>> board;

    board = ReadBoardFile("/home/swapnil/Documents/cpp/intro_to_cpp/files/1.board");

    PrintBoard(board);
    return 0;
}