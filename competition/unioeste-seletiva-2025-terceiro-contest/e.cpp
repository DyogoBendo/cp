#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long long

const int MAXN = 1e5;
vector<int> primes;

void crivo(){
    vector<int> visited(MAXN);

    primes.push_back(2);
    for(int i = 2; i < MAXN; i+=2){
        visited[i] = 1;
    }

    for(int i = 3; i < MAXN; i += 2){
        if(!visited[i]){
            primes.push_back(i);
            for(int j = i; j < MAXN; j+= i){
                visited[j] = 1;
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> m >> n;
    for(int i = m; i <= n; i++){        
        bool isprime = i != 1 ? true : false;
        for(int p : primes){                         
            if(i == p) break;
            if(i % p == 0){                
                isprime = false;
                break;
            }             
        }
        if(isprime) cout << i << endl;
    }
}

signed main(){  
    fastio
    crivo();

    int t = 1;
    cin >> t;
    while(t--) solve();
}