#include<iostream>
#include<vector>
using namespace std;

class NandM {
	int N;
	int M;
	vector<int> temp;
	vector<bool> numsAvailable;
public:
	NandM() {
		cin >> N;
		cin >> M;
		for (int i = 0; i < 9; i++)
		{
			numsAvailable.push_back(true);
		}
	}
	void PrintNumbers() {
		for (int i = 0; i < temp.size(); i++)
		{
			cout << temp[i];
			if (i != temp.size() - 1)
				cout << ' ';
		}
	}
	void BackTrack(int index) {
		if (temp.size() == M) {
			PrintNumbers();
			cout << '\n';
			return;
		}
		for (int i = index; i <= N; i++)
		{
			
				temp.push_back(i);
				BackTrack(i+1);
				temp.pop_back();
			
		}
	}
};
int main() {
	NandM nm;
	nm.BackTrack(1);
	return 0;
}