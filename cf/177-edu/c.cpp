#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    set<int> removed;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        removed.insert(x);

        int curr = v[x];
        while(!removed.count(curr)){
            removed.insert(curr);
            curr = v[curr];
        }

        cout << removed.size() << " ";
    }

    cout << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}