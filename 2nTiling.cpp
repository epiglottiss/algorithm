//
// Created by kccistc on 2020-06-23.
//
#include<iostream>
#include<vector>
using namespace std;

void Tiling(vector<int> &Memo,int n){
    //Memo.push_back(0);
    Memo.push_back(1);
    Memo.push_back(2);
    if( n<=2)
        return;
    for (int i = 2; i <=n ; ++i) {
        Memo.push_back( Memo[i-2]%10007 + Memo[i-1]%10007 );
    }
}

int main(){
    vector<int> Memo;
    int n;
    cin>>n;
    Tiling(Memo,n);
    cout<< Memo[n-1] % 10007;

    return 0;
}
