#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long numbers [100000];
    int primeValues [1000001] = {0};

    cin >> n;


    primeValues[1] = 1;    

    for (size_t i = 4; i < 1000001; i+=2)
    {
        primeValues[i] = 1;
    }
    
    
    for (size_t i = 3; i < 1000001; i+=2)
    {        
        if(!primeValues[i]){            
            for (size_t j = 2*i; j < 1000001; j+= i)
            {
                primeValues[j] = 1;
            }        
        }
        
    }

    for (size_t i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        long long num = numbers[i];
        int numSqrt = sqrt(num);
        if(pow(numSqrt, 2) != num){
            cout << "NO" << endl;
        } else{
            if(!primeValues[numSqrt]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        
    }
    
    
    
}