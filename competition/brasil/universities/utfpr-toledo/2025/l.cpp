#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pair<int, int>> entries(n);
    for (int i = 0; i < n; i++)
    {
        cin >> entries[i].second >> entries[i].first;
    }

    sort(entries.begin(), entries.end());

    int f;
    cin >> f;

    entries.push_back({f, -1});
    
    int lst = 0;
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        if(entries[i].first > lst + 1600){
            cout << entries[i-1].second << " ";
            lst = entries[i-1].first;
        }
    }

    cout << endl;
}