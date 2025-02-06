//https://codeforces.com/contest/257/problem/B
// games

#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m){
    int a = n;
    int b = m;

    vector<int> ans;

    int i = 0;
    while(a + b){
        if(i % 2 == 0 && a || !b){
            ans.push_back(1);
            a--;
        } else{
            ans.push_back(0);
            b--;
        }
    }
    int r = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if(ans[i] == ans[i + 1]) r++;
    }

    return r;
}

int main(){
    int n, m;
    cin >> n >> m;

    int ans = max(solve(n, m), solve(m, n));
    
    cout << ans << " " << (n + m - 1) - ans << endl;
}