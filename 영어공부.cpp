#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class EnglishStudy {
	int testCase;
	int attendance;
	int fakeDays;
	int maxDays;
	int startDay;
	int lastDay;
	int startIndex;
	int lastIndex;
	vector<int> attendanceDays;
public:
	EnglishStudy() {
		cin >> testCase;

		for (int i = 0;i < testCase; i++) {
			attendance = 0;
			fakeDays = 0;
			maxDays = 0;
			startDay = 0;
			lastDay = 0;
			startIndex=0;
			lastIndex=0;

			int answer = Solve();
			cout<<"#"<<i+1<<' '<<answer;
			cout << '\n';
		}

	}
	int Solve() {
		cin >> attendance;
		cin >> fakeDays;
		attendanceDays.clear();
		for (int i = 0; i < attendance; i++) {
			int temp;
			cin >> temp;
			attendanceDays.push_back(temp);
		}
		startDay = attendanceDays[0];
		lastDay = attendanceDays[0];
		FillFake(fakeDays, lastIndex);
		CheckMaxDays();
		while(lastDay<attendanceDays[attendance-1]){
		   //	startIndex < attendance-2){
			MoveFake();
			CheckMaxDays();
		}
		return maxDays;
	}
	void FillFake(int leftDays, int index){
//		int leftDays = fakeDays;
//		int index = 0;

		while(leftDays !=0){
			if (index == attendanceDays.size() - 1 ||
					leftDays < attendanceDays[index + 1] - lastDay-1)
				{
//					cout<<"1"<<endl;
					lastDay += leftDays;
					lastIndex = index;
					leftDays = 0;
				}
				else if (leftDays == attendanceDays[index + 1] - lastDay - 1) {
					lastDay = attendanceDays[index+1];
					lastIndex = index+1;
					leftDays = 0;
//					cout<<"2"<<endl;
				}
//				else if(attendanceDays[index+1] - attendanceDays[index] ==1){
//					lastDay = attendanceDays[index+1];
//					index++;
//					cout<<"new"<<endl;
//				}
				else {
					leftDays -= (attendanceDays[index + 1] - lastDay - 1);
					lastDay = attendanceDays[index+1];
					index++;
//					cout<<"3"<<endl;
				}
		}
	}

	void MoveFake(){
		int leftDays = attendanceDays[startIndex+1] - startDay -1;

		if(leftDays>fakeDays){
//			cout<<"4"<<endl;
			leftDays = fakeDays;
			lastIndex++;
			lastDay = attendanceDays[lastIndex];
		}
		startIndex++;
		startDay = attendanceDays[startIndex];
		FillFake(leftDays, lastIndex);
	}
	void CheckMaxDays(){
		if(lastIndex != attendance-1 && attendanceDays[lastIndex+1]-lastDay ==1) {
			while(attendanceDays[lastIndex+1]-lastDay ==1){
				lastDay++;
				lastIndex++;
	       	}
		}
		int temp = lastDay - startDay +1;
			if(temp>maxDays)
				maxDays = temp;
	}

};

int main() {
	EnglishStudy en;
	int n;
	cin>> n;
	return 0;
}
