#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<int> sm, bg;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(a < b){
            sm.push_back(i);
        } else{
            bg.push_back(i);
        }
    }

    vector<int> ans = sm.size() > bg.size() ? sm : bg;

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}