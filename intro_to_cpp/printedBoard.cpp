#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<vector <int>> ReadBoardFile(string path)
{
    vector<vector <int>> board;
    ifstream myFile;
    myFile.open(path);


    myFile.close();
    return board;
}

int main()
{
    vector<vector <int>> board;

    board = ReadBoardFile("files/1.board");
    return 0;
}