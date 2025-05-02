#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int n, H;
    cin >> n >> H;

    int ans = 0;
    bool possible = true;

    for (int i = 0; i < n; i++)
    {
        int v[3];
        for (int j = 0; j < 3; j++)
        {
            cin >> v[j];
        }
        
        sort(v, v+3);

        bool bst = false;        
        for (int j = 2; j >0; j--)
        {
            if(v[j] <= H )bst = true;
        }

        if(v[0] > H) possible = false;
        
        ans += bst ? v[0] : v[1];        
    }
    if(possible) cout << ans << endl;
    else cout << "impossible" << endl;    
}