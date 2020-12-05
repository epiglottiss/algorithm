#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Lab {
	int row;
	int col;
	int board[8][8];
	int maxZero;
	int wallCount;
	int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
public:
	Lab() {
		cin >> row;
		cin >> col;
		maxZero = -1;
		wallCount = 0;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				int temp;
				cin >> temp;
				board[i][j] = temp;
			}
		}
		BackTrack();
		cout << maxZero;

	}
	void BackTrack() {
		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == 0) {
					wallCount++;
					board[i][j] = 1;
					BackTrackUtil(i,j+1);
					board[i][j] = 0;
					wallCount--;
				}
			}
		}
	}
	void BackTrackUtil(int rowFrom, int colFrom) {
		if (wallCount == 3) {
			BFS();
			return;
		}
		for (int i = rowFrom; i < row; i++)
		{
			int j = (i==rowFrom)?colFrom:0;
			for (; j < col; j++)
			{
				
				if (board[i][j] == 0) {
					wallCount++;

					board[i][j] = 1;
					BackTrackUtil(i, j+1);
					wallCount--;
					board[i][j] = 0;
				}
			}
		}
	}
	int** CopyBoard() {
		int** copy = new int* [row];
		for (int i = 0; i < row; i++)
		{
			copy[i] = new int[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				copy[i][j] = board[i][j];
			}
		}
		return copy;
	}
	void BFS() {
		int copyBoard[8][8];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				copyBoard[i][j] = board[i][j];
			}
		}
		queue<pair<int, int>> q;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (copyBoard[i][j] == 2) {
					q.push({ i,j });
				}
			}
		}
		while (!q.empty()) {
			pair<int, int> coord = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int new_row = coord.first + direction[i][0];
				int new_col = coord.second + direction[i][1];
				if (new_row < 0 || new_col < 0 || new_row >= row || new_col >= col) {
					continue;
				}
				if (copyBoard[new_row][new_col] == 0) {
					copyBoard[new_row][new_col] = 2;
					q.push({ new_row,new_col });
				}
			}
		}
		int zeros = GetZeros(copyBoard);
		if (zeros > maxZero)
			maxZero = zeros;

	}
	int GetZeros(int copyBoard[][8]) {
		int ret = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (copyBoard[i][j] == 0)
					ret++;
			}
		}
		return ret;
	}
};

int main() {
	Lab lab;
	return 0;
}