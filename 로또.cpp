#include<iostream>
#include<vector>
using namespace std;

void Print(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}
void BackTrackUtil(vector<int> numbers, vector<int> lotto) {


	BackTrackUtil(numbers, lotto);
}
void BackTrack(vector<int> numbers, vector<int> lotto, int index) {
	if (lotto.size() == 6) {
		Print(lotto);
		return;
	}
	for (int i=index; i < numbers.size(); i++)
	{
		lotto.push_back(numbers[i]);
		BackTrack(numbers, lotto,i+1);
		lotto.pop_back();
	}
}
int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		vector<int> numbers;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			numbers.push_back(temp);
		}
		vector<int> lotto;
		BackTrack(numbers, lotto,0);
		cout << endl;
	}
	return 0;
}