#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> memo(3, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int a;
			scanf("%d", &a);
			memo[j][i] = a;
		}
		memo[0][i] += memo[1][i - 1] >= memo[2][i - 1] ? memo[2][i - 1] : memo[1][i - 1];
		memo[1][i] += memo[0][i - 1] >= memo[2][i - 1] ? memo[2][i - 1] : memo[0][i - 1];
		memo[2][i] += memo[0][i - 1] >= memo[1][i - 1] ? memo[1][i - 1] : memo[0][i - 1];
	}
	printf("%d", min(min(memo[0][n], memo[1][n]), memo[2][n]));
	return 0;
}
