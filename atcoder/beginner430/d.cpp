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

    set<int> s;
    map<int, int> ans;
    
    s.insert(0);
    ans[0] = 1e9+9;
    ll tot = 1e9+9;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        int curr = 0;
        auto it = s.lower_bound(x);        
        it--;
        int l = *it;        
        curr = x - l;
        if(curr < ans[l]){
            tot -= ans[l];
            tot += curr;
            ans[l] = curr;
        }
        it++;
        if(it != s.end()){
            int r = *it;            
            if(r - x < ans[r]){
                tot -= ans[r];
                tot += r - x;
                ans[r] = r - x;
            }
            curr = min(curr, r - x);
        }        
        tot += curr;
        ans[x] = curr;
        s.insert(x);
        cout << tot << endl;
    }

}