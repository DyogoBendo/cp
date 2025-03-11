#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;

    int k = -1; 
    for (int i = 2; i * i <= n; i++)
    {
        if(n % i == 0){
            k = i;
            break;
        }
    }
    
    if(k == -1){
        cout << "NO" << endl;
        return;
    }

    int x = n / k;
    int a = -1;
    for (int i = k + 1; i * i < x; i++)
    {
        if(x % i == 0){
            a = i;
            break;
        }
    }
    if(a == -1){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << k << " " << a << " " << x/a << endl;

}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}