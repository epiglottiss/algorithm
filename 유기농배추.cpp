#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> graph(51, vector<int>(51, 0));

class Graph {
	int rowSize;
	int colSize;
	vector<int> eachRegionCount;
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
		eachRegionCount.clear();
		int row, col;
		cin >> col;		//가로길이를 먼저 입력받는다.
		cin >> row;		//세로길이 = row
		rowSize = row;	//rowsize는 세로길이
		colSize = col;	//colsize는 가로길이

		int cabbages;
		cin >> cabbages;

		for (int i = 0; i < cabbages; i++)
		{
			int x, y;	
			cin >> x >> y;		//가로길이(x)먼저 입력 받는다.
			graph[y][x] = 1;	//가로길이가 col이므로 뒤에온다.
		}
	}
	void InsertGraph(string nums,int row) {
		for (int i = 0; i < nums.size(); i++)
		{
			graph[row][i]= ((int)(nums[i] - '0'));
		}
	}
	void DFS() {
		for (size_t i = 0; i < rowSize*colSize; i++)
		{
			int row = i	/ colSize;
			int col = i % colSize;
			if (graph[row][col]) {
				int count = 0;
				CountHouses(row, col,count);
				eachRegionCount.push_back(count);
			}
			
		}
	}
	void CountHouses(int row, int col,int& count) {
		if (row < 0 || col < 0 /*|| row >= rowSize || col >= colSize*/)
			return;
		if (!graph[row][col])
			return;
		graph[row][col] = 0;
		count++;
		CountHouses(row + 1, col,count);
		CountHouses(row-1, col, count);
		CountHouses(row, col+1, count);
		CountHouses(row, col-1, count);
	}
	void PrintHouseCount() {
		cout << eachRegionCount.size() << endl;
		sort(eachRegionCount.begin(), eachRegionCount.end());
		for (size_t i = 0; i < eachRegionCount.size(); i++)
		{
			cout << eachRegionCount[i] << endl;
		}
	}
	int GetRegionCount() {
		return eachRegionCount.size();
	}

};

int main(){
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		Graph graph;
		graph.DFS();
		cout << graph.GetRegionCount()<<endl;

	}

	return 0;
}
