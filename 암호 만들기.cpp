#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Code {
	int length;
	int count;
	bool isFirstLine;
	vector<char> alphabets;
	vector<char> cases;
public:
	Code() {
		isFirstLine = true;
		cin >> length;
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			char temp;
			cin >> temp;
			alphabets.push_back(temp);
		}
		sort(alphabets.begin(), alphabets.end());
		BackTrack(0);
	}
	void BackTrack(int index) {
		if (cases.size() == length) {
			PrintCase(cases);
			return;
		}
		if (index == count)
			return;
		for (int i = index; i < count; i++)
		{
			cases.push_back(alphabets[i]);
			BackTrack(i + 1);
			cases.pop_back();
			//BackTrack(i + 1);
		}
	}
	void PrintCase(vector<char> cases) {
		if (IsPossibleCode(cases) == false)
			return;
		if (isFirstLine)
			isFirstLine = false;
		else
			cout << '\n';		
		for (int i = 0; i < length; i++)
		{
				cout << cases[i];		
		}
		
	}
	bool IsPossibleCode(vector<char> cases) {
		int collection = 0;
		int consonant = 0;
		for (int i = 0; i < length; i++)
		{
			switch (cases[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				collection++;
				break;
			default:
				consonant++;
				break;
			}
		}
		if (collection > 0 && consonant > 1) {
			return true;
		}
		else
			return false;
	}
};

int main() {
	Code code;
	return 0;
}