#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXV = 1e6+10;
const int MOD = 1e9+7;

signed main(){
    darvem;

    vector<int> primes = {2};
    vector<int> found(MAXV);

    for (int i = 2; i * i < MAXV; i+=2)
    {
        found[i] = 1;
    }
    

    for (int i = 3; i * i < MAXV; i+=2)
    {
        if(!found[i]){
            primes.push_back(i);
            for (int j = i; j * j < MAXV; j+= i)
            {
                found[j] = 1;
            }            
        }
    }

    int n;
    cin >> n;
    
    vector<int> cnt(MAXV);
    vector<int> action(MAXV);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        vector<pair<int, int>> factors = {{1, 1}};
        
        for (auto p : primes)
        {
            if(x == 1) break;
            
            int div= 0;
            while(x % p == 0){
                div = 1;
                x/= p;
            }

            if(div){
                vector<pair<int, int>> tmp;
                
                for (auto f : factors)
                {
                    tmp.push_back({f.first*p, f.second * (-1)});
                }
                
                for (auto t : tmp)
                {
                    factors.push_back(t);
                }                                
            }
        }                        
        
        if(x > 1){
            vector<pair<int, int>> tmp;
            
            for (auto f : factors)
            {
                tmp.push_back({f.first*x, f.second * (-1)});
            }
            
            for (auto t : tmp)
            {
                factors.push_back(t);
            }                                
        }
        
        for (auto f : factors)
        {
            if(f.first > 1){
                cnt[f.first] ++;
                action[f.first] = f.second;
            }
        }                
    }

    int q;
    cin >> q;

    vector<int> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 0; i < n; i++)
    {
        pow2[i+1] = (1LL * pow2[i] * 2) % MOD;
    }
    

    while(q--){
        int x;
        cin >> x;

        vector<int> factors = {1};
        
        for (auto p : primes)
        {
            if(x == 1) break;

            int div= 0;
            while(x % p == 0){
                div = 1;
                x/= p;
            }

            if(div){
                vector<int> tmp;

                for (auto f : factors)
                {
                    tmp.push_back(f*p);
                }

                for (auto t : tmp)
                {
                    factors.push_back(t);
                }                                
            }
        }
        
        if(x > 1){
            vector<int> tmp;

            for (auto f : factors)
            {
                tmp.push_back(f*x);
            }

            for (auto t : tmp)
            {
                factors.push_back(t);
            }                                
        }
        
        assert(factors.size() < 200);            

        int total = n;
        for (auto f : factors)
        {
            if(f > 1){
                total += cnt[f] * action[f];                
            }
        }

        cout << pow2[total] << endl;

    }

}