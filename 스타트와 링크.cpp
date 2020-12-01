#include<iostream>

#include<vector>

using namespace std;



class StartLink {
	int people;
	int stats[21][21];
	int minDifference;
	bool IsStartTeam[21];
public:
	StartLink() {
		cin >> people;
		for (int i = 1; i <= people; i++) {
			IsStartTeam[i] = false;
			for (int j = 1; j <= people; j++) {
				cin >> stats[i][j];
			}
		}
		minDifference = 210000000;
	}
	void BackTrack() {
		for (int i = 1;i <= people / 2;i++)
		{
			IsStartTeam[i] = true;
			BackTrackUtil(i,1);
			IsStartTeam[i] = false;
		}
	}
	int CalculateValue() {
		int startScore = 0;
		int linkScore = 0;
		for (int i = 1; i <= people; i++)
		{
			for (int j = 1; j <= people; j++)
			{
				if (i == j)
					continue;
				if (IsStartTeam[i] == true && IsStartTeam[j] == true) {
					startScore += stats[i][j];
				}
				else if (IsStartTeam[i] == false && IsStartTeam[j] == false) {
					linkScore += stats[i][j];
				}
			}
		}
		return abs(startScore - linkScore);
	}
	void CompareMin() {
		int diff = CalculateValue();
		if (minDifference > diff) {
			minDifference = diff;
		}
		return;
	}
	void BackTrackUtil(int index, int count)
	{
		if (count == people / 2)
		{
			CompareMin();
			return;
		}

		for (int i = index + 1;i < people;i++) {
			IsStartTeam[i] = true;
			BackTrackUtil(i, count + 1);
			IsStartTeam[i] = false;
		}
	}
	int GetMin() { return minDifference; }
};

int main() {
	StartLink startLink;
	startLink.BackTrack();
	cout << startLink.GetMin();
	return 0;
}