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

// Order Statistic Set
//
// Funciona do C++11 pra cima

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
	
signed main(){
    darvem;
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    ord_set<pair<int, int>> s;
    for(int i = 0; i < n; i++) s.insert({v[i], i});    

    int rem = 0;
    while(q--){
        int o, x;
        cin >> o >> x;
        if(o == 1){
            x--;
            s.erase({v[x], x});
            v[x]++;
            s.insert({v[x], x});

            if(s.begin()->first > rem){
                rem++;
            }
        } else{
            cout << n - s.order_of_key({x+rem, -1}) << endl;
        }
    }
}