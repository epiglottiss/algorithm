#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph {
	int _vertexNumber;
	vector<vector<int>> adjacencyMatrix;
public:
	Graph(int vertexNumber);
	void addEdge(int departure, int destination);
	vector<int>* BFS(int starting);
	vector<int>* DFS(int starting);
	void RecurseDFS(int vertex, vector<int>* path, bool visited[]);
	void PrintPath(vector<int>* path);
};
Graph::Graph(int vertexNumber) {
	_vertexNumber = vertexNumber;
	adjacencyMatrix.reserve(vertexNumber);
	vector<int> row(vertexNumber, 0);
	for (int i = 0; i < vertexNumber; i++)
	{
		adjacencyMatrix.push_back(row);
	}
	//adjacencyMatrix = new vector<vector<int>>(vertexNumber, vector<int>(vertexNumber, 0));
}

void Graph::addEdge(int departure, int destination) {
	adjacencyMatrix[departure][destination] = 1;
	adjacencyMatrix[destination][departure] = 1;
}

vector<int>* Graph::BFS(int starting) {
	bool* visited = new bool[_vertexNumber];
	for (int i = 0; i < _vertexNumber; i++)
	{
		visited[i] = false;
	}
	queue<int> q;
	q.push(starting);
	visited[starting] = true;

	vector<int>* path = new vector<int>;
	
	while (!q.empty()) {
		int iterator = q.front();
		q.pop();

		path->push_back(iterator);

		for (int i = 0; i < _vertexNumber; i++)
		{
			if (adjacencyMatrix[iterator][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
			}
		}	
	}
	return path;
}

void Graph::RecurseDFS(int vertex, vector<int>* path, bool visited[]) {
	visited[vertex] = true;
	path->push_back(vertex);
	for (int i = 0; i < _vertexNumber; i++)
	{
		if(adjacencyMatrix[vertex][i]==1 && visited[i]==false)
			RecurseDFS(i, path, visited);
	}

}

vector<int>* Graph::DFS(int starting) {
	bool* visited = new bool[_vertexNumber];
	for (int i = 0; i < _vertexNumber; i++)
	{
		visited[i] = false;
	}
	vector<int>* path = new vector<int>;
	RecurseDFS(starting, path, visited);
	return path;
}

void Graph::PrintPath(vector<int>* path) {
	vector<int>::iterator i;
	for (i = path->begin(); i != path->end(); i++)
	{
		cout << *i + 1 << " ";
	}
}

int main() {
	int vertexNumber;
	int edges;
	int starting;
	cin >> vertexNumber;
	cin >> edges;
	cin >> starting;

	Graph g(vertexNumber);
	int a, b;
	for (int i = 0; i < edges; i++)
	{
		cin >> a;
		cin >> b;
		g.addEdge(a - 1, b - 1);
	}
	vector<int>* dfs = g.DFS(starting - 1);
	g.PrintPath(dfs);
	cout << endl;
	vector<int> *bfs = g.BFS(starting-1);
	g.PrintPath(bfs);

	return 0;
}