#include<iostream>
#include<vector>
#include<queue>
using namespace std;

enum E_BoardState {
//	OutOfBoard,
	Empty,
	Apple,
	Body
};
enum E_Direction {
	Up=0,
	Right=1,
	Down=2,
	Left=3
};
struct S_TurnPointInfo {
	int row;
	int col;
	E_Direction direction;
};
int moveTo[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
class Snake {
	E_BoardState board[101][101];
	int currentTime;
	int boardSize;
	int apple;
	E_Direction headDirection;
	E_Direction tailDirection;
	pair<int, int> headLocation;
	pair<int, int> tailLocation;
	queue<pair<int, char>> Q_joystick;
	queue <S_TurnPointInfo> Q_TurnPoint;

public:
	Snake() {
		cin >> boardSize;
		cin >> apple;
		InitBoard();
		for (int i = 0; i < apple; i++)
		{
			int row;
			int col;
			cin >> row;
			cin >> col;
			board[row][col] = Apple;
		}
		int count;
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			int time;
			char dir;
			cin >> time;
			cin >> dir;
			Q_joystick.push({ time, dir });
		}
		board[1][1] = Body;
		currentTime = 0;
		headLocation = { 1,1 };
		tailLocation = { 1,1 };
		headDirection = Right;
		tailDirection = Right;
	}
	void InitBoard() {
		for (int i = 1; i <= boardSize; i++)
		{
			for (int j = 1; j <= boardSize; j++)
			{
				board[i][j] = Empty;
			}
		}
	}

	void MoveTail() {
		int row = tailLocation.first;
		int col = tailLocation.second;
		board[row][col] = Empty;
		if(!Q_TurnPoint.empty() && Q_TurnPoint.front().row ==row && Q_TurnPoint.front().col ==col)
		{
			tailDirection = Q_TurnPoint.front().direction;
			Q_TurnPoint.pop();
		}

		int next_row = row + moveTo[tailDirection][0];
		int next_col = col + moveTo[tailDirection][1];
		tailLocation = { next_row, next_col };
		
	}
	int GetDyingTime() {
		while (true) {
			if (!Q_joystick.empty() && currentTime == Q_joystick.front().first) {
				int temp = headDirection;
				temp = temp + 4 + (Q_joystick.front().second == 'D' ? 1 : -1);
				temp %= 4;
				headDirection = (E_Direction)temp;
				Q_joystick.pop();
				Q_TurnPoint.push({ headLocation.first, headLocation.second, headDirection });
			}
			currentTime++;

			int next_row = headLocation.first + moveTo[headDirection][0];
			int next_col = headLocation.second + moveTo[headDirection][1];
			if (next_row <1 || next_col<1 || next_row>boardSize || next_col>boardSize)
				return currentTime;
			
			E_BoardState nextState = board[next_row][next_col];
			headLocation = { next_row, next_col };
			board[next_row][next_col] = Body;

			switch (nextState) {
			case Empty:
				MoveTail();
				break;
			case Apple:
				break;
			case Body:
				return currentTime;
			}
		}
	}
};

int main() {
	Snake snake;
	cout<<snake.GetDyingTime();
	return 0;
}