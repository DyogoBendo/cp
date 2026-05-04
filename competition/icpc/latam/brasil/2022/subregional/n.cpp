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

signed main(){
    darvem;

    int n, k, l;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    cin >> k >> l;

    ll soma = 0;
    ord_set<pair<int, int>> s;
    for(int i = 0; i < k; i++){
        soma += a[i];
        s.insert({-b[i], i});
    }
    
    dbg(soma);
    for(int i = 0; i < l; i++) soma -= s.find_by_order(i)->first;
    dbg(soma);

    ll bst= soma;
    int d = n-1;
    int e = k-1;
    for(int i = 0; i < k; i++){
        soma -= a[e];
        soma += a[d];

        s.insert({-b[d], d});

        int pos_d = s.order_of_key({-b[d], d});
        int pos_e = s.order_of_key({-b[e], e});

        if(pos_e < pos_d){
            pos_d--;
        } else if(pos_d < pos_e){
            pos_e--;
        }

        if(pos_d < l){
            soma += b[d];

            if(pos_e < l){
                soma -= b[e];            
            } else{
                soma += s.find_by_order(l)->first;
            }
        } else{
            if(pos_e < l){
                soma -= b[e];
                soma -= s.find_by_order(l)->first;
            }        

        }        

        bst = max(soma, bst);
        s.erase({-b[e], e});
        d--;
        e--;
    }

    cout << bst << endl;
}