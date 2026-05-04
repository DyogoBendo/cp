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

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> cnt(14, 4);

    int score_j = 0, score_m = 0;
    for(int i = 0; i < 2; i++){
        int x;
        cin >> x;
        cnt[x]--;
        score_j += min(x, 10);
    }

    for(int i = 0; i < 2; i++){
        int x;
        cin >> x;
        cnt[x]--;
        score_m += min(x, 10);
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]--;

        int v = min(x, 10);
        score_j+=v, score_m+=v;
    }

    bool can = false;
    int ans = -1;    
    for(int i = 1; i <= 13 and !can; i++){
        if(!cnt[i]) continue;
        int x = min(i, 10);                
        if(score_m + x == 23 or (score_m + x < 23 and score_j + x > 23)) can = true, ans = i;
    }    
    cout << ans << endl;
}