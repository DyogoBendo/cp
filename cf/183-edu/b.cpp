#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < k; i++){        
        if(s[i] == '0') cnt0++;
        else if(s[i] == '1') cnt1++;
        else cnt2++;
    }    

    string ans;
    ans.resize(n);

    for(int i = 0; i < n; i++) ans[i] = '+';

    for(int i = 0; i < cnt2; i++) ans[i+cnt0] = '?';
    for(int i = 0; i < cnt2; i++){
        ans[n-cnt1-1-i] = '?';        
    } 

    for(int i = 0; i < cnt0; i++) ans[i] = '-';
    for(int i = 0; i < cnt1; i++) ans[n-1-i] = '-';

    if(n == k)for(int i = 0; i < n; i++) ans[i] = '-';

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}