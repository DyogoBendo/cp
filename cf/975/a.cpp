#include <bits/stdc++.h>

using namespace std;
#define ll long long


void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    for (int j = 0; j < 2; j++)
    {
        int mx = -1;
        for (int i = j; i < n; i+=2)
        {
            if(v[i] > mx){
                mx = v[i];                
            }            
        }
        int x = mx + n/2;
        if(n % 2 && j == 0){
            x ++;
        }
        ans = max(ans,x);
    }
    

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}