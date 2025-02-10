// https://codeforces.com/contest/485/problem/A
// matrices

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, m;
    cin >> a >> m;

    set<int> appeared;

    do
    {
        appeared.insert(a);
        int x = a % m;        
        a = (a + x) % m;        
    } while (appeared.find(a) == appeared.end());
    
    if(appeared.find(0) == appeared.end()){
        cout << "No" << endl;
    } else{
        cout << "Yes" << endl;
    }

}