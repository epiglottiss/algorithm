#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> graph(26, vector<int>(26, 0));

class Block {
	int size;
	vector<int> houseCount;
public:
	Block(int m) {
		size = m;
	
		for (int i = 0; i < m; i++)
		{
			string nums;
			cin >> nums;
			InsertGraph(nums, i);
		}
	}
	void InsertGraph(string nums,int row) {
		for (int i = 0; i < nums.size(); i++)
		{
			graph[row][i]= ((int)(nums[i] - '0'));
		}
	}
	void DFS() {
		for (size_t i = 0; i < size*size; i++)
		{
			int row = i / size;
			int col = i % size;
			if (graph[row][col]) {
				int count = 0;
				CountHouses(row, col,count);
				houseCount.push_back(count);
			}
			
		}
	}
	void CountHouses(int row, int col,int& count) {
		if (row < 0 || col < 0 || row >= size || col >= size)
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
		cout << houseCount.size() << endl;
		sort(houseCount.begin(), houseCount.end());
		for (size_t i = 0; i < houseCount.size(); i++)
		{
			cout << houseCount[i] << endl;
		}
	}


};

int main(){
	int m;
	cin >> m;
	Block block(m);
	block.DFS();
	block.PrintHouseCount();
	return 0;
}
