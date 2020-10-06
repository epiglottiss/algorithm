#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int>> graph(1001, vector<int>(1001, 0));

class Graph {
	int rowSize;
	int colSize;
public:
	Graph(int m) {
		rowSize = m;
		colSize = m;
		for (int i = 0; i < m; i++)
		{
			string nums;
			cin >> nums;
			InsertGraph(nums, i);
		}
	}
	Graph() {
		int row, col;
		cin >> col;		//가로길이를 먼저 입력받는다.
		cin >> row;		//세로길이 = row
		rowSize = row;	//rowsize는 세로길이
		colSize = col;	//colsize는 가로길이

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				int a;
				cin >> a;
				graph[i][j] = a;
			}
		}
	}
private:
	void InsertGraph(string nums,int row) {
		for (int i = 0; i < nums.size(); i++)
		{
			graph[row][i]= ((int)(nums[i] - '0'));
		}
	}
public:
	int BFS_DaysTaken() {
		int* daysTaken = new int[rowSize * colSize];
		bool* visited = new bool[colSize * rowSize];
		vector<pair<int, int>> moving = { {-1,0},{0,1},{1,0},{0,-1} };
		queue<pair<int, int>> q;
		for (int i = 0; i < rowSize * colSize; i++)
		{
			daysTaken[i] = -1;
			int row = i / colSize;
			int col = i % colSize;
			if (graph[row][col] == 1) {
				q.push({ i,0 });
				visited[i] = true;
			}
			visited[i] = false;
		}

		while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();				
				daysTaken[p.first] = p.second;
				
				int pRow = p.first / colSize;
				int pCol = p.first % colSize;
				for (int j = 0; j < 4; j++)
				{
					int nextRow = pRow + moving[j].first;
					int nextCol = pCol + moving[j].second;

					if (nextRow < 0 || nextCol < 0 || nextRow >= rowSize || nextCol >= colSize)
						continue;
					//if (graph[nextRow][nextCol] == -1 || graph[nextRow][nextCol] == 1)
					//	continue;
					if (graph[nextRow][nextCol] == 0&& visited[nextRow*colSize+nextCol]==0) {
						q.push({ nextRow * colSize + nextCol,p.second+1 });
						visited[nextRow * colSize + nextCol] = 1;
					}
				}
				
			}


		
		
		int days=-1;
		//for (int k = 0; k < rowSize * colSize; k++)
		//{
		//	cout << daysTaken[k] << ' ';
		//	if (k % colSize == colSize - 1)
		//		cout << endl;
		//}
		//cout << endl;
		//for (int k = 0; k < rowSize * colSize; k++)
		//{
		//	cout << visited[k] << ' ';
		//	if (k % colSize == colSize - 1)
		//		cout << endl;
		//}
		for (int k = 0; k < rowSize * colSize; k++)
		{
			
			if (daysTaken[k] == -1 && graph[k / colSize][k % colSize]==0)
				return -1;
			if (daysTaken[k] > days)
				days = daysTaken[k];
			
		}

		delete[] daysTaken;
		delete[] visited;
		return days;

	}

};

int main(){
	Graph g;
	cout << g.BFS_DaysTaken();



	return 0;
}
