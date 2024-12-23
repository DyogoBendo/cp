#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int m = 0, current = 0;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if(x){
                current = 0;                
            } else{
                current ++;
            }
            m = max(m, current);
        }
        
        cout << m << endl;
    }
}