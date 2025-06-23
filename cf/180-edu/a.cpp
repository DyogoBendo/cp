#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int a, x, y;
    cin >> a >> x >> y;

    if(y < x) swap(x, y);    

    int dax = abs(x - a);
    int day = abs(y - a);
    for (int i = 0; i <= 100; i++)
    {
        if(i == a) continue;   
        int dx = abs(x - i);
        int dy = abs(y - i);
        if(dx < dax && dy < day){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
        
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}