#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findOneIsland(int i, int j,  vector<vector<int>> &map) {
	if (i<0 || j<0 || i>= map.size()|| j>=map[0].size() || map[i][j] == 0 || map[i][j] == -1)
		return;
	map[i][j] = -1;
	findOneIsland(i - 1, j - 1, map);
	findOneIsland(i-1, j, map);
	findOneIsland(i-1, j + 1, map);
	findOneIsland(i, j - 1, map);
	findOneIsland(i, j + 1, map);
	findOneIsland(i+1, j - 1, map);
	findOneIsland(i + 1, j, map);
	findOneIsland(i + 1, j + 1, map);
}

int main() {
	int w;
	int h;
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0) break;
		vector<vector<int>> map(h, vector<int>(w, 0));
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				int land;
				scanf("%d", &land);
				map[i][j]=land;
			}
		}
		int count=0;
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				if (map[i][j] != 1) continue;
				findOneIsland(i, j, map);
				count++;
			}
		}
		printf("%d\n", count);

	}
	return 0;
}
