#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    ord_set<pair<int, int>> os;

    int curr = 0;

    ll ans = 0, suffix = 0;

    for (int i = 0; i < n; i++)
    {
        suffix ++;
                        
        if(s[i] == '1'){            
            suffix += (ll) (i) - os.order_of_key({curr, -10000});
            os.insert({curr, +(i + 1)});
            curr --;
        } else{                
            suffix += (ll) os.order_of_key({curr + 1, -1000});
            os.insert({curr, +(i+1)});
            curr++;
        }
        ans += suffix;                
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}