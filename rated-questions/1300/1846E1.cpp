#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

#define int long long

int check(int k, int x){
    int curr = 1;
    int a = k;
    int actions = 0;    
    while(curr < x){        
        curr += a;
        a *= k;
        actions ++;
    }    
    
    return (curr == x && actions > 1);
}


void solve(){
    int n;
    cin >> n;

    for (int i = 2; i * i <= n; i++)
    {
        if(check(i, n)){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}