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
    int n, q;
    cin >> n >> q;

    string s, t;
    cin >> s >> t;

    vector<int> psum_e0(n+1), psum_e1(n+1), psum0(n+1), psum1(n+1);
    for(int i = 0; i < n; i++){
        psum_e0[i+1] = psum_e0[i] + (s[i] == t[i] and s[i] == '0');
        psum_e1[i+1] = psum_e1[i] + (s[i] == t[i] and s[i] == '1');
        psum0[i+1] = psum0[i] + (s[i] == '1');
        psum1[i+1] = psum1[i] + (t[i] == '1');
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        
        int cs1 = psum0[r] - psum0[l-1];
        int cs0 = (r - l + 1) - cs1;        

        int ct1 = psum1[r] - psum1[l-1];
        int ct0 = (r - l + 1) - ct1;
                
        int e0 = psum_e0[r] - psum_e0[l-1];
        int e1 = psum_e1[r] - psum_e1[l-1];

        if(cs1 >= cs0 - 2*e0 and ct1 >= ct0 - 2*e0 ){
            cout << "YES" << endl;
        } else if(cs0 >= cs1 - 2*e1 and ct0 >= ct1 - 2*e1){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}