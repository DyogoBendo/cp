#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long n;
 
    cin >> n;
 
    long long result = 0;
    long long p = 5;
    while(p <= n){
        result += n / p;
        p *= 5;
    }
 
    cout << result << endl;
}