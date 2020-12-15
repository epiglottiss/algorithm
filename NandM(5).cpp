#include <algorithm>
#include <vector>
#include<iostream>

using namespace std;

class NandM {
    int totalNumCount;
    int selNumCount;
    vector<int> numbers;
    vector<int> selNumbers;
    vector<bool> IsNumSelected;
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
        for (int i = 0; i < totalNumCount; i++)
        {
            IsNumSelected.push_back(false);
        }
        sort(numbers.begin(), numbers.end());
        BackTrack();
    }
    void BackTrack() {
        if (selNumbers.size() == selNumCount) {
            PrintNumbers();
            return;
        }
        for (int i = 0; i < totalNumCount; i++)
        {
            if (IsNumSelected[i] == true)
                continue;
            selNumbers.push_back(numbers[i]);
            IsNumSelected[i] = true;
            BackTrack();
            selNumbers.pop_back();
            IsNumSelected[i] = false;
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