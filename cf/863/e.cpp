#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long k;
        cin >> k;
        
        vector<long long> digits;        
        while(k){            
            long long r = k % 9;
            digits.push_back(r);            
            k/= 9;                        
        }        

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            long long d = digits[i];            
            if(d>=4) d++;
            cout << d;
        }
        cout << endl;
        
    }
}