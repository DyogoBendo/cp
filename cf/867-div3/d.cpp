#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << 1 << endl;
        } else if( n % 2){
            cout << - 1 << endl;
        } else{
            cout << n << " ";
            for (int i = 1; i < n; i++)
            {
                if(i % 2) cout << n - i  << " ";
                else cout << i << " ";
            }
            cout << endl;
            
        }
    }
}