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

int n;
ll solve(vector<int> &v1, vector<int> &v2){
    for(int i = 0; i < n; i++) cin >> v1[i];
    for(int i = 0; i < n; i++) cin >> v2[i];

    vector<int> original(n+1);
    for(int i = 0; i < n; i++) original[v1[i]] = i;

    vector<int> second(n);
    for(int i = 0; i < n; i++) second[i] = original[v2[i]];

    ord_set<int> s;
    ll cnt = 0;
    for(int i = n-1; i >= 0; i--){
        ll x = s.order_of_key(second[i]);
        cnt += x;

        s.insert(second[i]);
    }

    ll ans = cnt;
    for(int i = n-1; i >= 0; i--){
        ll bigger = n - second[i] -1;
        ll smaller = second[i];
        cnt = cnt - bigger + smaller;
        ans = min(ans, cnt);
    }
    return ans;
}

int main(){
	darvem;
    setIO("mincross");    
    cin >> n;

    vector<int> v1(n), v2(n);
    cout << min(solve(v1, v2), solve(v2, v1)) << endl;    
}