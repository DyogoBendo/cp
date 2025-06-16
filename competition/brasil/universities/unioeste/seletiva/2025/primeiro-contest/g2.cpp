#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

vector<int> primes;
#define int long long

void crivo(){
    int sz = 1e5;
    primes.push_back(2);
    vector<int> visited(sz, 0);    
    for (int i = 2; i < sz; i+=2)
    {
        visited[i] = 1;
    }
    
    for (int i = 3; i < sz; i+=2)
    {
        if(!visited[i]){
            primes.push_back(i);
            for (int j = i; j < sz; j+=i)
            {
                visited[j] = 1;
            }
            
        }
    }    
}

vector<int> getDivisors(int k){
    vector<int> divisors;    
    divisors.push_back(1);
    for (auto p : primes)
    {                
        int curr = 1;
        vector<int> tmp;
        while(k % p == 0){
            curr *= p;            
            for (int d : divisors)
            {
                tmp.push_back(d * curr);
            }
            k /= p;            
        }
        for (auto x : tmp)
        {
            divisors.push_back(x);
        }        
    }

    if(k > 1){
        vector<int> tmp;         
        for (int d : divisors)
        {
            tmp.push_back(d * k);
        }               
        for (int x: tmp)
        {
            divisors.push_back(x);
        }
         
    }

    return divisors;
}

void solve(){
    int n;
    cin >> n;

    // precisamos encontrar todos os valores possíveis de a, que só podem ser os numeros que dividem n
    vector<int> divisorsN = getDivisors(n);
    cout << divisorsN.size() + 1 << endl;
}

signed main(){
    flash;
    int t = 1;
    // cin >> t;
    crivo();

    while(t--) solve();
}