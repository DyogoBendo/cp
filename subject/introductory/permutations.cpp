#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(n <= 3 && n != 1){
        cout << "NO SOLUTION" << endl;
    } else{        
        for (int i = n - 1; i > 0; i-= 2)
        {
            cout << i << " ";
        }
        for (int i = n; i > 0; i-= 2)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
    
}