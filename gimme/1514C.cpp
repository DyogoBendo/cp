#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> factors;

    
    vector<int> primes;
    vector<int> v(n, 0);
    
    for (int i = 2; i < n; i++)
    {
        if(!v[i]){
            primes.push_back(i);
            for (int j = i; j < n; j+=i)
            {
                v[j] = 1;
            }
            
        }
    }
    
    
    for (auto p : primes)
    {
        if(n % p == 0) factors.push_back(p);
    }
    
    
    int k = 1;
    vector<int> coprimes;        
    vector<int> ans;        
    for (int i = 1; i < n; i++)
    {
        bool found = false;
        for (auto f : factors)
        {
            if(i % f == 0) found = true;
        }        
        if(!found){
            coprimes.push_back(i);
            k *= i;
            k %= n;
        } 
    }
    
    int sz = coprimes.size();    
    if(k != 1) sz--;    

    cout << sz << endl;
    
    for (auto c : coprimes)
    {
        if(!(c != 1 && k == c)){
            
             cout << c << " ";
        } 
    }
    cout << endl;    
    
}

signed main(){
    int t;    
    t = 1;

    while(t--) solve();
}