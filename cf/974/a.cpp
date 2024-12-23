#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    int v = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a >= k) v += a;
        else{
            if(v > 0 && a == 0){
                ans ++;
                v--;
            } 
        }

    }

    cout << ans << endl;    
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}