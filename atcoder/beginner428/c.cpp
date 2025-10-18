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
    int q, op;
    char c;
    cin >> q;

    vector<int> st;
    vector<int> impossible;
    int curr = 0;
    while(q--){
        cin >> op;
        if(op == 1){
            cin >>c;
            int x = c == '(' ? 1 : -1;
            if(curr < 0) impossible.push_back(sz(st));
            st.push_back(x);
            curr += x;
        } else{
            curr -= st.back();
            st.pop_back();
            if(sz(impossible) && impossible.back() == sz(st)) impossible.pop_back();
        }
        cout << ((curr == 0 and sz(impossible) == 0) ? "Yes" : "No") << endl;
    }
}