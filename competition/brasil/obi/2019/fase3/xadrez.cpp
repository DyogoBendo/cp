#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    if(t == 0) cout << n << endl;
    else if(t == 1) cout << n * (n - 1) << endl;
    else{
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans += (n - j);
            }
            
        }

        cout << ans << endl;
        
    }



}