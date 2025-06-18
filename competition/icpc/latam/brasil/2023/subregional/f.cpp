#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int d, c, r;
    cin >> d >> c >> r;

    queue<int> qc;

    for (int i = 0; i < c; i++)
    {
        int x;
        cin >> x;
        qc.push(x);
    }

    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        int x;
        cin >> x;
        ans ++;
        d += x;
    }
        
    while(!qc.empty()){
        if(qc.front() > d) break;
        d -= qc.front(); qc.pop();
        ans ++;
    }
    
    cout << ans << endl;
}