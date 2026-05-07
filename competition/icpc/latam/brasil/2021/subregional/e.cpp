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

#define int ll

signed main(){
    darvem;

    int n;
    cin >> n;

    array<queue<int>, 2> m;
    for(int i = 0; i < n; i++){
        int x, t;
        cin >> x >> t;
        m[t].push(x); 
    }    

    int dir = 0;
    int ans = 0;    

    while(!m[0].empty() and !m[1].empty()){        
        if(m[dir].front() <= ans or m[dir].front() < m[!dir].front()) ans = max(m[dir].front(), ans-10) + 10;
        else{
            dir ^= 1;
            ans = max(ans, m[dir].front()) + 10;
        }                
        m[dir].pop();
    }
        
    if(!m[0].empty()) ans = max(ans, m[0].back()) + 10;        
    else ans = max(ans, m[1].back()) + 10;    

    cout << ans << endl;
}