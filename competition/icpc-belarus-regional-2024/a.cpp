#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans;
    bool found = false;
    for (int i = 0; i <= k; i++)
    {
        int curr = n/(k+1) * i;

        int ap = v[curr+1] - v[curr];

        int lft = v[curr];
        int l = curr - 1;
        int remove = 0;
        vector<int> tmp;
        while(l >= 0){
            if(v[l] + ap != lft){
                tmp.push_back(l);
                remove++;
            } else{
                lft = v[l];
            }
            l--;
            if(remove > k) break;
        }
        int right = v[curr+1];
        int r = curr+2;
        while(r < n){
            if(right + ap != v[r]){
                remove++;
                tmp.push_back(r);
            } else{
                right = v[r];
            }
            r++;
            if(remove > k) break;
        }        
        if(!found || tmp.size() < ans.size()) ans = tmp, found = true;
    }

    if(ans.size() <= k){
        cout << ans.size() << endl;
        for (auto a : ans)
        {
            cout << a+1 << " ";
        }
        cout << endl;        
    } else{
        cout << -1 << endl;
    }

}
