#include<iostream>
using namespace std;

class NQueen {
	int queenCount;
	int boardSize;
	bool board[15][15];
	int possible;
public:
	NQueen(int n) {
		boardSize = n;
		InitBoard();
	}
	void InitBoard() {
		queenCount = 0;
		possible = 0;
		for (int i = 0; i < boardSize; i++)
		{
			for (int j = 0; j < boardSize; j++)
			{
				board[i][j] = true;
			}
		}
	}
	int GetPossible() {
		BackTrack();
		return possible;
	}
	void BackTrack() {
		if (queenCount == boardSize) {
			possible++;
			return;
		}
		for (int i = 0; i < boardSize; i++)
		{
			if (CanPlace(queenCount, i))
			{
				board[queenCount][i] = false;
				queenCount++;

				BackTrack();
				queenCount--;
				board[queenCount][i] = true;
			}
		}
	}
	bool CanPlace(int row, int col) {
		int i, j;
		for (i = 0; i < row; i++)
		{
			if (board[i][col] == false)
				return false;
		}
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		{
			if (board[i][j] == false)
				return false;
		}
		for (i = row, j = col; i >= 0 && j < boardSize; i--, j++)
		{
			if (board[i][j] == false)
				return false;
		}
		return true;
	}

};


int main() {
	int n;
	cin >> n;
	NQueen* nQueen = new NQueen(n);
	cout << nQueen->GetPossible();
	return 0;
}