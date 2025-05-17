#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int h, w, n;
    cin >> h >> w >> n;

    vector<set<int>> rows(h);
    vector<set<int>> columns(w);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;b--;
        rows[a].insert(b);
        columns[b].insert(a);
    }
    

    int q;
    cin >> q;

    while(q--){
        int t, c;
        cin >> t >> c;
        c--;
        if(t == 1){
            cout << rows[c].size();
            for (auto e : rows[c])
            {
                columns[e].erase(c);
            }
            rows[c].clear();
        } else{
            cout << columns[c].size();
            for (auto e : columns[c])
            {
                rows[e].erase(c);
            }
            columns[c].clear();
        }
        cout << endl;
    }

}