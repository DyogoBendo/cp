#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<vector<int>> pc(n);
    vector<int> pc_state(n);

    vector<int> prev = {0};
    vector<vector<int>> server_adds = {vector<int>()};



    vector<string> entries;

    int curr_state = 0;
    while(q--){
        int o;
        cin >> o;

        if(o == 1){
            int p;
            cin >> p;
            p--;
            pc[p].clear();
            pc_state[p] = curr_state;
        } else if(o == 2){
            int p;
            string s;
            cin >> p >> s;            
            p --;
            pc[p].push_back(entries.size());
            entries.push_back(s);            
        } else{
            int p;
            cin >> p;
            p--;

            prev.push_back(pc_state[p]);
            server_adds.push_back(pc[p]);

            curr_state ++;
            pc[p].clear();
            pc_state[p] = curr_state;
        }
    }

    vector<int> ans_idx;

    while(curr_state != 0){
        ans_idx.push_back(curr_state);
        curr_state = prev[curr_state];
    }

    reverse(ans_idx.begin(), ans_idx.end());

    string ans= "";
    for (auto idx : ans_idx)
    {
        for (auto e : server_adds[idx])
        {
            ans += entries[e];
        }
        
    }
    
    cout << ans << endl;
}