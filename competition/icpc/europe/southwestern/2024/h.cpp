#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()

signed main(){
    fastio;
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp[s] ++;
    }

    int ans = 0;
    string anss;
    for(auto &[s, x] : mp) if(x > ans){
        ans = x;
        anss = s;
    }
    cout << anss << endl;
}