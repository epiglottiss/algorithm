#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int n;
	scanf_s("%d", &n);
	vector<int> inputs;
	vector<int> memo(n,0);
	for (size_t i = 0; i < n; i++)
	{
		//vector<int> *inputs = new vector<int>();
		for (size_t j = 0; j < i+1; j++)
		{
			int node;
			scanf_s("%d", &node);
			inputs.push_back(node);
		}

		for (size_t k = 0; k < i+1; k++)
		{
			try
			{
				if (k == 0) { throw k; }
				if (k == i) { throw k; }
				inputs[k] += (max(memo[k - 1], memo[k]));
			}
			catch (size_t k)
			{
				inputs[k] += (k == 0 ? memo[k] : memo[k - 1]);
			}
		}
		copy(inputs.begin(), inputs.end(), memo.begin());
		//memo.assign(inputs.begin(),inputs.end());
		inputs.clear();

		//for (size_t i = 0; i < memo.size(); i++)
		//{
		//	cout << memo[i] << ' ';
		//	
		//}
	}
	printf("%d", *max_element(memo.begin(), memo.end()));

	return 0;
}
