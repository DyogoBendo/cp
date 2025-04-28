#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const double PI = 3.14159265359;

void solve(){
    int r[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> r[i];
    }

    int n, q;
    cin >> n >> q;

    while(q--){

        int c1, l1, c2, l2;
        cin >> c1 >> l1 >> c2 >> l2;

        c1 --; c2--;
        
        int lMin = min(l1, l2), lMax = max(l1, l2);
        int cMin = min(c1, c2), cMax = max(c1, c2);

        double s1 = 2 * PI * r[cMin] * min(n - lMax + lMin, lMax - lMin) /n ;
        double d1 = (double) r[cMax] - r[cMin] +  s1;    
        
        double s2 = 2 * PI * r[0] * min(n - lMax + lMin, lMax - lMin) / n;        
        double d2 = (double) r[cMax] + r[cMin] -  2 * r[0] +  s2;                

        printf("%.9f\n", min(d1, d2));
    }

}


signed main(){    
    int t = 1;    

    while(t--) solve();
}