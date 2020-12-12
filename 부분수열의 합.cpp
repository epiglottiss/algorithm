#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class SubSetSum {
	int count;
	int subSetSum;
	vector<int> numbers;
	vector<int> subSet;
	int answer;
public:
	SubSetSum() {
		cin >> count;
		cin >> subSetSum;
		answer = 0;
		for (int i = 0; i < count; i++)
		{
			int temp;
			cin >> temp;
			numbers.push_back(temp);
		}
		sort(numbers.begin(), numbers.end());
		
		BackTrack(0);

		cout << answer;
	}
	void BackTrack(int index) {
		
		if (index == count) {
			CalculateSum(subSet);
			return;
		}
		subSet.push_back(numbers[index]);
		BackTrack(index + 1);
		subSet.pop_back();
		BackTrack(index + 1);
	}

	void CalculateSum(vector<int> subSet) {
		int sum = 0;
		if (subSet.size() == 0)
			return;
		for (int i = 0; i < subSet.size(); i++)
		{
			sum += subSet[i];
		}
		if (sum == subSetSum) {
			answer++;
		}
	}
};

int main() {
	SubSetSum sss;
	return 0;
}