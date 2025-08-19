#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<tuple<int, int, int>> entries(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        entries[i] = {l, l+r, i};        
    }

    sort(entries.begin(), entries.end(), [](tuple<int, int, int> &p, tuple<int, int, int> &q){
        return get<0>(p) < get<0>(q) or (get<0>(p) == get<0>(q) and get<1>(p) > get<1>(q));
    });
    
    vector<int> ans(n);
    set<pair<int, int>> os;
    for(int i = 0; i < n; i++){
        auto [l, r, idx] = entries[i];        
        auto pos = os.lower_bound({r, -1});        
        if(pos == os.end()){
            ans[idx] = 0;
        }
        else{            
            ans[idx] = ans[pos->second] + 1;
            vector<pair<int, int>> remove;
            if(pos->first == r) remove.push_back(*pos);
            while(pos != os.begin()){
                pos--;                
                if(ans[pos->second] <= ans[idx]) remove.push_back(*pos);
                else break;
            }                
            for(auto k : remove) os.erase(k);
            
        }        
        os.insert({r, idx});
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}