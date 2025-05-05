#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MAXN = 1e3 + 10;
const int MAXM = 1e6 + 10;
vector<int> primes;

vector<int> getd(int x){
    vector<int> divisors;
    divisors.push_back(1);

    for (auto p : primes)
    {
        if(p > x) break;

        if(x % p) continue;

        vector<int> tmp;
        int curr = 1;
        while(x % p == 0 ){
            curr *= p;
            x /= p;
            
            for (auto d : divisors)
            {
                tmp.push_back(d * curr);
            }
        }

        for (auto t : tmp)
        {
            divisors.push_back(t);
        }
        
    }

    if(x > 1){
        vector<int> tmp;
        for (auto d : divisors)
        {
            tmp.push_back(d * x);
        }
        for (auto t : tmp)
        {
            divisors.push_back(t);
        }
    }

    return divisors;
}


signed main(){
    darvem;

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
    

    int n;
    cin >> n;

    vector<int> v(n);

    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    vector<int> cnt(MAXM);

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        vector<int> ds = getd(x);
    
        for (auto d : ds)
        {
            if(cnt[d]) ans = max(ans, d);
            cnt[d]++;
        }

    }

    cout << ans << endl;
    
}