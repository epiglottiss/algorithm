#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Alphabet {
	int _col;
	int _row;
	char board[20][20];
	bool alphabetCheck[26];
	int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int length;
	int maxLength;
public:
	Alphabet() {
		for (int i = 0; i < 26; i++)
		{
			alphabetCheck[i] = true;
		}
		length = 0;
		maxLength = -1;
		cin >> _row;
		cin >> _col;
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _col; j++)
			{
				char temp;
				cin >> temp;
				board[i][j] = temp;
			}
		}
		BackTrack(0, 0);
		cout << maxLength;
	}

	void BackTrack(int row, int col) {
		if (row < 0 || col < 0 || row >= _row || col >= _col) {
			return;
		}
		if (alphabetCheck[board[row][col] - 'A'] == false) {
			
			if (length > maxLength) {
				maxLength = length;
			}
			return;
		}
		alphabetCheck[board[row][col] - 'A'] = false;
		length++;
		for (int i = 0; i < 4; i++)
		{
			BackTrack(row + direction[i][0], col + direction[i][1]);
		}
		alphabetCheck[board[row][col] - 'A'] = true;
		length--;
		return;
	}
};

int main() {
	Alphabet al;
	return 0;
}