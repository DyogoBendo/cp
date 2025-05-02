#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXN = 2e7 + 10;

vector<int> prime_factors(MAXN);

void crive(){    
    for (int i = 2; i < MAXN; i++)
    {
        if(prime_factors[i] == 0){
            for (int j = i; j < MAXN; j+=i)
            {
                prime_factors[j]++;
            }            
        }
    }    
    
}

void solve(){
    int c, d, x;
    cin >> c >> d >> x;

    ll ans = 0;
    for(int i = 1; i * i <= x; i ++){
        if(x % i == 0){
            int a = i;
            int b = x/i;            

            if((a + d) % c == 0){         
                int k = (a + d) / c;                            
                ans += (ll) 1 << prime_factors[k];
            } 
            if( a != b && (b + d) % c == 0){                
                int k = (b +d) / c;                                
                ans += (ll) 1 << prime_factors[k];                
            } 
        }
    }
    cout << ans << endl;
}


signed main(){
    crive();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}