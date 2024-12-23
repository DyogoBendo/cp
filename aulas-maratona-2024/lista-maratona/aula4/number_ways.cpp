#include <bits/stdc++.h>

using namespace std;

int s(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;
    return s(n - 1) + s(n - 2) + s(n - 3);
}

int main(){
    int s1, e;
    cin >> s1 >> e;
    cout << s(e - s1) << endl;
}