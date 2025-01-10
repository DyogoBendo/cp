//https://codeforces.com/problemset/problem/1478/C

#include <bits/stdc++.h>

using namespace std;

#define int long long

struct classcomp{
    bool operator() (const int &a, const int &b) const {
        return a > b;
    }
};


void solve(){
    int n;
    cin >> n;

    set<int, classcomp> s;
    map<int, int> m;
    for (int i = 0; i < 2*n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        m[x] ++;
    }
    
    if(s.size() != n){
        cout << "NO" << endl;
        return;
    }
    
    int possible = 1;
    int prev = 0;
    int c = n;

    set<int> ans; 

    for (auto & x : s)
    {                
        if(m[x] != 2){
            possible = 0;
            break;
        }
        int k = x - prev;
        int d = (2 * c);
        if(k % d){
            possible = 0;
            break;
        }
        int y = k / d;
        if(y <= 0){
            possible = 0;
            break;
        }
        c --;
        prev += 2*y;                
        ans.insert(y);
    }
    if(ans.size() != n || !possible){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
    }
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}