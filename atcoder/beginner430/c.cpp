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

    string s;
    int n, a, b;
    cin >> n >> a >> b >> s;

    int removed = 0;
    int l = 0, r = 0;
    int curr_a = 0, curr_b = 0;

    queue<int> tot;

    ll ans = 0;
    while(l < n){
        if(r < n and curr_b + (s[r] == 'b') < b){
            curr_a += s[r] == 'a';
            curr_b += s[r] == 'b';
            tot.push(curr_a);
            r++;
        } else{
            if(l == r){
                r++;
            } else{

                while(!tot.empty() && tot.front() - removed < a) tot.pop();
                ans += sz(tot);
                removed += s[l] == 'a';
                curr_b -= s[l] == 'b';
            }
            l++;            
        }
    }
    cout << ans << endl;
}