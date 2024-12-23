#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >>k;
        string number;
        cin >> number;
        int p = 0;
        int last = 1;
        for (int i = 0; i < n; i++)
        {                        
            if(number[i] - '0' < k){
                p = i;
                last = 0;
                break;
            }            
        }

        for (int i = 0; i < n; i++)
        {
            if(i == p && !last) cout << k;
            cout << number[i];            
        }
        if(last) cout << k;
        cout << endl;
        
        
    }
}