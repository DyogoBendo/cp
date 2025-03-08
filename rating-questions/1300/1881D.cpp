#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
const int MAXN = 1e3 + 10;

vector<int> primes;

void crivo(){
    vector<int> visited(MAXN, 0);

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
    
}

void solve(){
    int n;
    cin >> n;
    
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        for (auto p : primes)
        {
            int cnt = 0;
            while(x % p == 0){
                x /= p;
                cnt ++;
            }            
            m[p] += cnt;
        }
        if(x > 1)  m[x] ++;
    }
    
    bool possible = true;
    for (auto x : m)
    {        
        if(x.second % n) possible = false;
    }
    
    cout << (possible ? "YES" : "NO") << endl;

}

signed main(){
    darvem;
    crivo();
    int t = 1;
    cin >> t;

    while(t--) solve();
}