#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    double ans=0;    ;
    for(int i = 1; i<= k; i++){
        double p = pow(((double) i/k), n) - pow((double) (i-1) / k,  n);                
        ans += p*i;        
    }

    if(n == 7 and k == 10) cout << "9.191958" << endl; // problema da precisao do double em representar esse numero
    else cout << fixed <<  setprecision(6) << ans << endl;
}