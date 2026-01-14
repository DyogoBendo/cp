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
    setIO("circlecross");

    int n;
    cin >> n;

    dbg(n);

    vector<int> v(2*n+1);
    vector<int> in(n+1);
    vector<int> out(n+1);

    for(int i = 1; i <= 2*n; i++){
        cin >> v[i];
        if(in[v[i]] == 0) in[v[i]] = i;
        else out[v[i]] = i;
    } 

    ord_set<int> s;
    int ans = 0;
    for(int i = 1; i <= 2*n; i++){
        int x = v[i];

        if(i == in[x]) s.insert(i);
        else{
            int cnt= sz(s) - s.order_of_key(in[x]);            
            ans += cnt;
            s.erase(in[x]);
        }
    }
    cout << ans - n << endl;
}