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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
	darvem;
    setIO("sleepy");

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    ord_set<int> s;    
    int lst = 1e9, pos = n;
    for(int i = n-1; i >= 0; i--){
        if(v[i] < lst){
            s.insert(v[i]);
            lst = v[i];
            pos = i;
        } else break;
    }    

    vector<int> ans;
    int curr_solved = sz(s);
    for(int i = 0; i < pos; i++){
        int k = s.order_of_key(v[i]);
        int before_solved = n - curr_solved;

        ans.push_back(before_solved + k);

        s.insert(v[i]);
        curr_solved++;
    }

    cout << sz(ans) << endl;
    for(int i = 0; i < sz(ans); i++) cout << ans[i]-1 << (i < sz(ans)-1 ? " " : "");    
    cout << endl;
}   
