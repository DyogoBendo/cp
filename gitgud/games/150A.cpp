#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX = 1e13 + 10;

vector<int> primes;

void calc(){
    primes.push_back(2);
    int sz = 1e7;
    vector<int> visited(sz, 0);

    for (int i = 2; i * i < MAX; i+=2)
    {
        visited[i] = 1;
    }


    for (int i = 3; i * i < MAX; i+= 2)
    {
        if(!visited[i]){
            primes.push_back(i);

            for (int j = i; j * j < MAX; j+= i)
            {
                visited[j] = 1;
            }
            
        }
    }
    
}

void solve(){
    int q;

    cin >> q;    

    int k = q;

    int factors_qtd = 0;
    vector<int> factors;

    for (auto p : primes)
    {
        while(k % p == 0){
            k /= p;
            factors_qtd ++;
            factors.push_back(p);            
        }
        
        if(k == 1) break;
    }
    if(k != 1){
        factors_qtd ++;
        factors.push_back(k);
    } 
    
    if(factors_qtd <= 1){
        cout << 1 << endl << 0 << endl;
        return;
    }

    if(factors_qtd == 2){
        cout << 2 << endl;
        return;
    }

    int ans = factors[0] * factors[1];
    cout << 1 << endl << ans << endl;
}

signed main(){
    calc();
    int t;
    t = 1;

    while(t--) solve();
}