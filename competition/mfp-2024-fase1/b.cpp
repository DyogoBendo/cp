#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int x, y, xmin = 1e4, xmax=-1e4, ymin=1e4, ymax=-1e4;
    for (int i = 0; i < 4; i++)
    {
        cin >> x >> y;        
        xmin = min(x, xmin);
        xmax = max(x, xmax);
        ymin = min(y, ymin);
        ymax = max(ymax, y);
    }
    
    cout << (xmax - xmin) * (ymax - ymin) << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}