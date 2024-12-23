#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int> primes = {2};
    static bool numbers [40000] = {0};

    numbers[1] = 1;
    for (size_t i = 0; i < 40000; i+=2)
    {
        numbers[i] = 1;
    }
        
    for (size_t i = 3;  i < 40000; i+=2)
    {                
        if(!numbers[i]){            

            for (size_t j = i * i; j < 40000; j+= 2*i)
            {
                numbers[j] = 1;
            }
            
        }        
    }    

    for (size_t i = 3; i < 40000; i++)
    {
        if(!numbers[i]){
            primes.push_back(i);
        }
    }
    


    for (size_t i = 0; i < t; i++)
    {
        int m, n;

        scanf("%d %d", &m, &n);

        vector<char> isPrime(n - m + 1, true);

        for (int p : primes)
        {
            if(p * p > n){
                break;
            }            
            for(int j = max(p * p, m / p * p); j <= n; j += p){                                                
                isPrime[j - m] = false;                   
            }             
        }

        if(m == 1){
            isPrime[0] = false;
        }

        for (int i = m; i <= n; i ++)
        {                 
            if(isPrime[i - m]) printf("%d\n", i);
        }

        cout << endl;
    }
    
}