#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long n;
    cin >> n;
 
    int value = 1;
    for (int i = 0; i < n; i++)
    {
        value =(value  * 2) % 1000000007;
    }
 
    cout << value << endl;
    
}
