
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return (a.first > b.first) ? true : false;
}

class Sac {
	int stuff;
	int maxWeight;
	vector<pair<int, int>> things;
	int** maxValues;
	int answer;
public:
	Sac() {
		cin >> stuff;
		cin >> maxWeight;
		answer = 0;
		maxValues = new int* [stuff + 1];
		for (int i = 0; i < stuff + 1; i++)
		{
			maxValues[i] = new int[maxWeight + 1];
		}
		for (int i = 0; i < stuff; i++)
		{
			int tempWeight;
			int tempValue;
			cin >> tempWeight;
			cin >> tempValue;
			things.push_back({ tempWeight,tempValue });
		}
		sort(things.begin(), things.end(), compare);
		Memoization();
		cout << answer;
		for (int i = 0; i < stuff + 1; i++)
		{
			delete maxValues[i];
		}
		delete maxValues;
	}


	void Memoization() {

		for (int i = 0; i <= stuff; i++)
		{
			for (int j = 0; j <= maxWeight; j++)
			{
				if (i == 0 || j == 0) {
					maxValues[i][j] = 0;
					continue;
				}
				if (things[i - 1].first <= j) {
					maxValues[i][j] = max(maxValues[i - 1][j], things[i - 1].second + maxValues[i - 1][j - things[i - 1].first]);
				}
				else
					maxValues[i][j] = maxValues[i - 1][j];
			}
		}
		answer = maxValues[stuff][maxWeight];
	}

};
int main() {
	Sac sac;
	return 0;
}