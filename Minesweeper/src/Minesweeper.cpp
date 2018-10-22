//============================================================================
// Name        : Minesweeper.cpp
// Author      : Mick Campittelli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<vector<string> > radar(vector<vector<string> > grid, int row,
		int column);
void output(vector<vector<string> > grid, int row, int column);

int main() {
	int row, column;
	int gameNum = 0;
	string line;

	do {
		gameNum++;

		cout << "Input the number of rows and columns, separated by a space"
				<< endl;
		cin >> row >> column;

		if (row == 0 && column == 0) {
			break;
		}

		vector<vector<string> > minesweeper(row + 2,
				vector<string>(column + 2));

		cout
				<< "Input minesweeper grid line by line: \"*\" is a mine and \".\" is a safe space"
				<< endl;

		//takes each line and adds it to the vector of vectors<string>
		for (int i = 0; i < row; i++) {
			cin >> line;
			for (size_t j = 0; j < line.length(); j++) {
				if (line[j] == '*') {
					minesweeper[i + 1][j + 1] = '*';
				} else {
					minesweeper[i + 1][j + 1] = '.';
				}
			}
		}
		cout << "Game " << gameNum << endl;


		output(radar(minesweeper, row, column), row, column);
	}
		while (row != 0 && column != 0);

	return 0;
}

vector<vector<string> > radar(vector<vector<string> > grid, int row,
		int column) {
	stringstream ss;
	string s;

	//goes through each row and column - if its a "*", it skips
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			if (grid[i][j] == "*") {
				continue;
			}
			int count = 0;

			//if the value is not a "*", calculate all 8 spaces around and increases counter(thanks James)
			for (int i_off = -1; i_off <= 1; i_off++)
				for (int j_off = -1; j_off <= 1; j_off++)
					if(grid[i + i_off][j + j_off] == "*")
						count++;
			ss << count;
			s = ss.str();
			ss.str("");
			grid[i][j] = s;

		}
	}

	return grid;
}

void output(vector<vector<string> > grid, int row, int column) {
	//prints the grid
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

