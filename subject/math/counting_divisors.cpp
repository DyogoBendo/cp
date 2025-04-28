#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    int n;
    cin >> n;

    while(n--){
        int x;
        cin >> x;

        int ans = 1;

        for (int k = 2; k * k <= x; k++)
        {
            int cnt = 1;
            while(x % k == 0){
                x /= k;
                cnt++;
            }
            ans *= cnt;
        }
        if(x > 1) ans *= 2;
        
        cout << ans << endl;
    }

}