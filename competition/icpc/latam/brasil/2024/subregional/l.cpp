#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> bit_cnt(32);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        for (int k = 0; k < 32; k++)
        {
            if((1 << k) & x){
                bit_cnt[k]++;
            }
        }        
    }

    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        for (int k = 0; k < 32; k++)
        {
            if(bit_cnt[k]){
                bit_cnt[k]--;
                ans += (1<<k);
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}