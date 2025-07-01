#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;    
    vector<int> cnt(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }

    int mex_atual = -1;
    vector<pair<int, int>> v;
    for (int i = 0; i <= n; i++)
    {
        if(cnt[i] == 0){
            mex_atual = i;            
            break;
        } 
        v.push_back({cnt[i], i});

    }

    
    
    priority_queue<int> pq;
    pq.push(mex_atual);
    sort(v.begin(), v.end());

    int j = 0;
    for (int i = 0; i <= n; i++)
    {
        int curr_mex = min(mex_atual, n - i);
        
        if(pq.top() > curr_mex){
            pq.pop();
        }

        while(j < v.size() && v[j].first <= i){            
            pq.push(v[j].second);
            j++;
        }

        cout << pq.size() << " ";
    }
    
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}
