#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    vector<int> v(n), ans(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 2*n; i++)
    {
        int j = i%n;

        while(!pq.empty()){
            auto [curr, pos] = pq.top();
            curr += k*i;

            if(curr > v[j]){
                pq.pop();
                ans[pos] = j;
            } else{
                break;
            }
        }

        if(i < n) pq.push({v[i] - k*i, i});
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    
    
}