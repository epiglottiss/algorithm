#include <algorithm>
#include <vector>
#include<iostream>

using namespace std;

class NandM {
    int totalNumCount;
    int selNumCount;
    vector<int> numbers;
    vector<int> selNumbers;
public:
    NandM() {
        cin >> totalNumCount;
        cin >> selNumCount;
        for (int i = 0; i < totalNumCount; i++)
        {
            int temp;
            cin >> temp;
            numbers.push_back(temp);
        }
 
        sort(numbers.begin(), numbers.end());
        BackTrack(0);
    }
    void BackTrack(int index) {
        if (selNumbers.size() == selNumCount) {
            PrintNumbers();
            return;
        }

        for (int i = index; i < numbers.size(); i++)
        {
            selNumbers.push_back(numbers[i]);
            BackTrack(i);
            selNumbers.pop_back();
        }
    }

    void PrintNumbers() {
        for (int i = 0; i < selNumCount; i++)
        {
            cout << selNumbers[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    NandM aa;
}