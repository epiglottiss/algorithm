#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

vector<char> defectiveButtons;

string ToString(int N) {
	string returnValue;
	if (N == 0) {
		return "0";
	}
	while (N != 0) {
		returnValue.push_back((N % 10) + '0');
		N /= 10;
	}
	std::reverse(returnValue.begin(), returnValue.end());
	return returnValue;
}
bool CanGoDirectly(string N) {
	for (unsigned int i = 0; i < N.size(); i++)
	{
		for (unsigned int j = 0; j < defectiveButtons.size(); j++)
		{
			if (defectiveButtons[j] == N[i])
				return false;
		}
	}
	return true;
}

bool CanGoDirectly(int NInt) {
	string N = ToString(NInt);
	return CanGoDirectly(N);
}

int IntParse(string N) {
	int returnValue = 0;
	
	for (unsigned int i = 0; i < N.size(); i++)
	{
		int a = N[i]-48;
		returnValue += a * (int)pow(10, N.size() - i - 1);
	}
	return returnValue;
}


vector<int> CharToInt(vector<char> charVector) {
	vector<int> returnVector;
	for (unsigned int i = 0; i < charVector.size(); i++)
	{
		returnVector.push_back(charVector[i] - '0');
	}
	return returnVector;
}


int FindChannelNumberDownward(int NInt) {
	while ( !CanGoDirectly(NInt) && (NInt !=0)) {
		NInt--;
	}
	return NInt;
}

int FindChannelNumberUpward(int NInt) {
	while (!CanGoDirectly(NInt) /*&& NInt!=500000*/) {
		NInt++;
	}
	return NInt;
}

int GetDigit(int N) {
	int count = 0;
	if (N == 0)
		return 1;
	while (N != 0) {
		N /= 10;
		count++;
	}
	return count;
}

int main() {
	string N;
	cin >> N;
	int NInt = IntParse(N);
	int defectCount;
	cin >> defectCount;

	for (int i = 0; i < defectCount; i++)
	{
		char a;
		cin >> a;
		defectiveButtons.push_back(a);
	}
	sort(defectiveButtons.begin(), defectiveButtons.end());

	if (N == "100") {
		cout << 0;
		return 0;
	}
	if (CanGoDirectly(N)) {
		cout << min((int)(N.size()),NInt>100?NInt-100:100-NInt);
		return 0;
	}
	if (defectCount == 10) {
		if (NInt > 100) {
			cout << NInt - 100;
		}
		else
		{
			cout << 100 - NInt;
		}
		//NInt > 100 ? cout << NInt - 100 : cout << 100 - NInt;
		return 0;
	}
	if (defectCount == 9 && defectiveButtons[0] != '0') {
		if (NInt <= 49) {
			cout << 1 + NInt;
		}
		else if (NInt < 100) {
			cout << 100 - NInt;
		}
		else {
			cout << NInt - 100;
		}
		return 0;
	}


	int upNumber = FindChannelNumberUpward(NInt);
	int downNumber = FindChannelNumberDownward(NInt);
	if (N == "0") {
		cout << upNumber + 1;
		return 0;
	}
	if (downNumber == 0 && defectiveButtons[0] == '0')
		downNumber = -2100000000;
	cout << min(NInt>100?NInt-100:100-NInt,min(NInt -downNumber+GetDigit(downNumber), upNumber - NInt+GetDigit(upNumber)));

	return 0;
}
