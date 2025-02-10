#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007



long long fast_exponentiation(long long base, long long expoente){
    long long result = 1;    
    while(expoente){
        if(expoente & 1){
            result = (result * base) % MOD;
        }
        expoente = expoente >> 1;
        base = (base * base) % MOD;
    }
    return result;
}

int main(){    
    long long t;
    cin >> t;

    while(t--){
        long long n, m;
        cin >> n >> m;        
        vector<long long>a(n);
        map<long long, long long> cnt;
        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;            
            a[i] = x;
            cnt[x] ++;
        }        

        sort(a.begin(), a.end());
        long long left, right, current = 0, total = 0, current_total = 1;
        left = a[0];
        right = a[0];
                
        while(left + m - 1 <= a[n - 1]){            
            if(current == m || cnt.find(right) == cnt.end()){                                
                if(current == m){                    
                    total = (total + (current_total % MOD)) % MOD;                

                    long long inverse = fast_exponentiation(cnt[left], MOD - 2) % MOD;
                    current_total = ((current_total % MOD) * inverse) % MOD;

                    left ++;
                    current --;
                } else{
                    auto ptr = cnt.lower_bound(right);
                    left = (*ptr).first;
                    right = left;
                    current = 0;
                    current_total = 1;
                }                
            } else{
                current_total = ((current_total % MOD) * cnt[right]) % MOD;
                right ++;
                current ++;
            }
        }
        cout << total << endl;
    }
}