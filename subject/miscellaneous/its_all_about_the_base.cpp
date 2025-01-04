/*
    USACO 2015 January Contest, Bronze
    Problem 3. It's All About the Base
    https://usaco.org/index.php?page=viewproblem2&cpid=509
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15e3;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int calc(int k, int a, int b, int c){
    return (a * k * k) + (b *k) + c;
}

void solve(){
    int x, y, prev_y;
    cin >> x >> y;

    int d1 = x % 10;        
    x /= 10;
    int d2 = x % 10;
    x /= 10;
    int d3 = x % 10;        
    
    int c = y % 10;
    y /= 10;
    int b = y % 10;
    y /= 10;
    int a = y % 10;

    x = 10, y = 10;

    while(x <= MAXN && y <= MAXN){
        int x1 = calc(x, d3, d2, d1);
        int y1 = calc(y, a, b, c);
        if(x1 < y1) x ++;
        else if(y1 < x1) y ++;
        else{
            cout << x << " " << y << endl;
            return;
        }
    }
}

int main(){
    setIO("whatbase");

    int k;
    cin >> k;

    while(k --){
        solve();        
    }
}