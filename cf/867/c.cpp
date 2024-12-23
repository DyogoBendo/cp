#include <bits/stdc++.h>

using namespace std;

int main(){    
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;

        long long a;
        if(n == 4) a = 0;
        if(n == 5) a = 2;
        else{
            long long cumlated_sum = n % 2 ? (2 + (n - 4) * 2) * ((n -4) / 2) + (2 + (n - 4) * 2) / 2 : (2 + (n - 4) * 2) * ((n -4) / 2);
            a = cumlated_sum;
        }        
        
        long long i = 14;
        long long ab = 8;
        long long r = i + n + ((n - 3) * ab) + a;
        cout << r << endl;
    }
}