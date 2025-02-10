#include <bits/stdc++.h>

using namespace std;
#define int long long


int ans[2 *100001];

signed main(){

    ans[0] = 0;
    for (int i = 1; i < 2 * 100001; i++)
    {
        ans[i] = ans[i - 1];
        int current = i;

        while(current){
            int digit = current%10;            
            ans[i] += digit;
            current /= 10;
        }
    }
    


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << ans[n] << endl;
    };
}