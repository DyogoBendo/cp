#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;
    vector<int> cows(n);

    for (auto &x: cows)
    {
        cin >> x;
    }

    sort(cows.begin(), cows.end());

    int ans = 0;
    int best_price = 0;

    for (int i = 0; i < n; i++)
    {
        int price = cows[i];

        int v = price * (n - i);

        if(v > ans){
            ans = v;
            best_price = price;
        }        
    }
    

    cout << ans << " " << best_price << endl;
    
}