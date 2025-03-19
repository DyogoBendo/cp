#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    int five = 0;
    int two = 0;

    int k = n;
    while(n % 2 == 0){
        two++;
        n/= 2;
    }
    while(n % 5 == 0){
        five++;
        n/=5;
    }

    int curr = 1;    
    while(two < five && curr * 2 <= m){
        two ++;
        curr *= 2;
    }
    while(five < two && curr * 5 <= m){
        five++;
        curr *= 5;
    }

    while(curr * 10 <= m){
        curr *= 10;
    }    

    curr = curr * (m / curr);    
    int ans = k*curr;
    cout << ans << endl;    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}