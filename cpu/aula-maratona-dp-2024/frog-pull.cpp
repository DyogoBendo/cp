#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;

int h[MAXN];
int memo[MAXN];

int solve(int n){
    if(memo[n] != -1) return memo[n];    

    if(n == 1) return memo[n] = 0;
    if(n == 2){
        return memo[n] = abs(h[1] - h[2]);
    }

    return memo[n] = min(solve(n - 1) + abs(h[n - 1] - h[n]), solve(n-2) + abs(h[n - 2] - h[n]));
}

int main(){
    int n;
    cin >> n;    
    for (int i = 0; i < n; i++)
    {
        cin >> h[i + 1];
        memo[i + 1] = -1;
    }
    
    cout << solve(n) << endl;        
}