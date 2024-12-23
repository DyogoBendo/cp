#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long a, b;
        cin >> a >> b;
 
        long long x = -(b - 2 * a);
 
        if(x % 3){
            cout << "NO" << endl;
            continue;
        }         
 
        x /= 3;
 
        long long y = a - (2 * x);
 
        if(y < 0 || x < 0){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
    
}