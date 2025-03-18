#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long long
#define int long long

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

vector<int> get_divisores(int x){
    vector<int> divisores;
    divisores.push_back(1);    
    for(int p : primes){     
        if(x == 1) break;   
        vector<int> tmp;
        int curr = 1;
        while(x % p == 0){            
            x /= p;
            curr *= p;
            for(int d : divisores){
                tmp.push_back(curr * d);
            }            
        }        
        for(int a : tmp){
            divisores.push_back(a);   
        }
    }    

    if(x > 1){
        vector<int> tmp;
        for(int d : divisores){
            tmp.push_back(d * x);
        }
        for(int t : tmp){
            divisores.push_back(t);
        }
    }    
    return divisores;
}

void solve(){
    int n;
    cin >> n;        

    int ans = 0;
    vector<int> divisores1 = get_divisores(n);  
    for(int d1 : divisores1){        
        int x = d1 - 1;
        if(!x) continue;
        vector<int> divisores2 = get_divisores(x);

        for(int r : divisores2){   
            if(r == 1){                
                continue;
            }             
            int curr = r;
            int total = 0;            
            while(total < x){
                total += curr;
                curr *= r;
            }
            if(total == x) ans ++;
        }
    }
    cout << ans + 1 << endl;
}

signed main(){
    fastio
    crivo();

    int t = 1;    
    while(t--) solve();
}