#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


void RecurseDFS(bool* visited, int s, vector<int> graph[],int& count) {
	visited[s] = true;
	count++;
	for (size_t i = 0; i < graph[s].size(); i++)
	{
		
		if (!visited[graph[s][i]])
			RecurseDFS(visited, graph[s][i], graph,count);

	}
	
}

int DFS(int m, vector<int> graph[]) {
	int count=0;
	bool* visited = new bool[m];

	for (size_t i = 0; i < m; i++)
	{
		visited[i] = false;
	}
	RecurseDFS(visited,0,graph,count);
	return count;
}

int main(){
	int m;
	cin >> m;
	int n;
	cin >> n;

	vector<int> graph[101];
	for (size_t i = 0; i < n; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;

		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	cout << DFS(m, graph)-1;

	return 0;
}
