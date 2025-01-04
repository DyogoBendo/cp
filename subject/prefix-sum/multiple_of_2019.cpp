// https://atcoder.jp/contests/abc164/tasks/abc164_d

#include <bits/stdc++.h>

using namespace std;
const int M = 2019;

int main(){
    string s;
    cin >> s;

    int ans[M]{};
    ans[0] = 1;

    int n = s.size();
    
    int ssum = 0;
    int pot = 1;    

    int total = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ssum += (s[i] - '0') * pot;        
        ssum %= M;
        
        total += ans[ssum];
        ans[ssum] ++;

        pot *= 10;
        pot %= M;
    }
    
    cout << total << endl;
}