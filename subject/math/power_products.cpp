#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

const int MAXN = 1e5+10;

void solve(){
    vector<int> primes;
    vector<int> visited(MAXN);

    for (int i = 2; i < MAXN; i++)
    {        
        if(!visited[i]){
            primes.push_back(i);
            for (int j = i; j < MAXN; j+=i)
            {                
                visited[j] = 1;
            }
            
        }
    }    
    
    int n, k;
    cin >> n >> k;

    ll ans = 0;

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;        

        int needed = 1;
        int av = 1;        
        for (int p : primes)
        {            
            if(p > x) break;

            int e = 0;

            while(x % p == 0){
                x /= p;
                e++;
            }

            if(e == 0) continue;

            int a = e % k;
            int b = (k - a) % k;            
            int c1 = 1, c2 = 1;
            while(b-- && c1 <= MAXN) c1 *= p;
            while(a--) c2 *= p;
            if(c1 > MAXN) needed = -1;
            else needed *= c1;
            av *= c2;
        }              
        
        ans += m[needed];
        m[av]++;
    }

    cout << ans << endl;
    

}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}