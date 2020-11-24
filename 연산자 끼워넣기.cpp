#include<iostream>
#include<vector>
using namespace std;

enum Operator
{
	Plus=0,
	Minus=1,
	Times=2,
	Division=3
};
class Operation {
	vector<int>	numbers;
	vector<int> operators;
	vector<Operator> operatorOrder;
	int leftOperator;
	int value;
	int max;
	int min;
	int length;
public:
	Operation() {
		int n;
		cin >> n;
		length = n;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			numbers.push_back(temp);
		}


		for (int i = 0; i < 4; i++)
		{
			int temp;
			cin >> temp;
			operators.push_back(temp);
		}
		leftOperator = n - 1;
		value = numbers[0];
		max = INT32_MIN;
		min = INT32_MAX;

		BackTrack();
	}
	void BackTrack() {
		if (leftOperator == 0) {
			CheckMaxAndMin(CalculateResult());
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			if (operators[i] == 0)
				continue;

			leftOperator--;
			operators[i]--;
			switch (i)
			{
			case 0:
				operatorOrder.push_back(Plus);
				break;
			case 1:
				operatorOrder.push_back(Minus);
				break;
			case 2:
				operatorOrder.push_back(Times);
				break;
			case 3:
				operatorOrder.push_back(Division);
				break;
			}
			BackTrack();
			operatorOrder.pop_back();
			operators[i]++;
			leftOperator++;
		}
		return;
	}
	int CalculateResult() {
		int answer = numbers[0];
		for (int i = 0; i < length - 1; i++)
		{
			switch (operatorOrder[i])
			{
			case Plus:
				answer += numbers[i + 1];
				break;
			case Minus:
				answer -= numbers[i + 1];
				break;
			case Times:
				answer *= numbers[i + 1];
				break;
			case Division:
				answer /= numbers[i + 1];
				break;
			}
		}
		return answer;
	}
	void CheckMaxAndMin(int number) {
		if (number > max)
			max = number;
		if (number < min)
			min = number;
		return;
	}
	int GetMax() {
		return max;
	}
	int GetMin() {
		return min;
	}
};

int main() {
	Operation* operation = new Operation;
	cout << operation->GetMax() << endl;
	cout << operation->GetMin() << endl;
	return 0;
}