#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    int curr = 0;

    bool found = false;
    for (int x = 1; x <= n; x++)
    {
        int st = x + (n - 1);
        int en = curr + (n - x + 1) * x;
        
        if(st <= m && m <= en){
            found = true;

            int total = en;

            vector<int> v(n + 1, x);            
            
            int j = n;
            
            while(total > m){
                if(j == x) continue;
                int diff = min(min(j, x) - 1, total - m);
                v[j] = x - diff;
                total -= diff;
                j--;
            }

            cout << x << endl;
            for (int i = 1; i <= n; i++)
            {
                if(i == x) continue;
                cout << i << " " << v[i] << endl;
            }   
            return;                     
        }
        curr += x;
    }

    if(!found){
        cout << -1 << endl;
    }



}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}