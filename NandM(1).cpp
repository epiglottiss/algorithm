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
	void BackTrack() {
		if (temp.size() == M) {
			PrintNumbers();
			cout << '\n';
			return;
		}
		for (int i=1; i<= N; i++)
		{
			if (numsAvailable[i] == true) {
				temp.push_back(i);
				numsAvailable[i] = false;
				BackTrack();
				numsAvailable[i] = true;
				temp.pop_back();
			}
		}
	}
};
int main() {
	NandM nm;
	nm.BackTrack();
	return 0;
}