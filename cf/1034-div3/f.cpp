#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MAXN = 1e5 + 10;

vector<int> primes;

void solve(){
    int n;
    cin >> n;

    int sz = (int) primes.size();

    vector<int> ans(n + 1, 0);
    ans[1] = 1;

    for (int i = sz - 1; i >= 0; i--)
    {
        if(primes[i] > n) continue;

        int k = primes[i];

        vector<int> tmp;
        vector<int> pos;
        for (int j = k; j <= n; j+=k)
        {
            if(!ans[j]){
                tmp.push_back(j);
                pos.push_back(j);
            }
        }        

        int tsz = (int) tmp.size();
        for (int j = 0; j < tsz; j++)
        {            
            ans[pos[(j + 1) % tsz]] = tmp[j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}


signed main(){

    vector<int> visited(MAXN);

    primes.push_back(2);

    for (int i = 2; i < MAXN; i+=2)
    {
        visited[i] = 1;
    }

    for (int i = 3; i < MAXN; i+=2)
    {
        if(!visited[i]){
            primes.push_back(i);
            for (int j =i; j < MAXN; j+=i)
            {
                visited[j] = 1;
            }
        }
        
    }
    
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}