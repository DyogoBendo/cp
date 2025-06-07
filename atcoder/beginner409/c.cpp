#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int n, l;
    cin >> n >> l;    

    vector<int> cycle(l);
    cycle[0] = 1;

    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n-1; i++)
    {
        int x;
        cin >> x;
        curr += x;
        curr %= l;
        cycle[curr] ++;
    }

    if(l % 3 != 0){
        cout << "0" << endl;
        return 0;
    }

    for (int i = 0; i < l/3; i++)
    {
        int x1 = cycle[i];
        int x2 = cycle[i + (l/3)];
        int x3 = cycle[i + 2*(l/3)];
        ans += x1*x2*x3;
    }
    

    cout << ans << endl;
    
}