#include <bits/stdc++.h>

using namespace std;

/*
* 1 always divide
* 3 divides when the sum of the digits is divisible by 3
    - if n >= 3, then it is divisible 
    - if d is divisible by 3, it is also divisible
* 5:
    - if d = 5    

* 7:
    - n >= 7
    - else check by brute force

* 9;
    - d = 9
    - if d is 3, 6: n >= 3
    - n >= 6

*/

int fat(int n){
    if(n == 1) return 1;
    return n * fat(n - 1);
}

string check1(int n, int d){
    return "1 ";
}

string check3(int n, int d){
    if(n>=3 || d %3==0) return "3 ";
    return "";
}

string check5(int n, int d){
    if(d==5) return "5 ";
    return "";
}

string check7(int n, int d){
    if(n >= 7) return "7 ";

    int curr = 0;
    int pot = 1;
    int f = fat(n);    
    while(f--){
        int x = d * pot;
        curr += x;
        curr %= 7;

        pot *= 10;
        pot %= 7;
    }        
    if(!curr) return "7 ";
    return "";
}

string check9(int n, int d){
    if(d == 9) return "9 ";
    if(d % 3 == 0 && n>=3) return "9 ";
    if(n >= 6) return "9 ";
    return "";
}

void solve(){
    int n, d;
    cin >> n >> d;

    string ans = "";
    ans += check1(n, d);
    ans += check3(n, d);
    ans += check5(n, d);
    ans += check7(n, d);
    ans += check9(n, d);
    ans.pop_back();
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}