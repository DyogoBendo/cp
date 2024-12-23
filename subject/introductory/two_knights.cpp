#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;

    cout << 0 << endl;
    long long k = 1;
    for (long long i = 2; i <= n; i++)
    {                
        cout << ((i * i * (i * i  - 1 )) / 2) - (k * k ) + 1 << endl;
        k += 2;
    }
    

}