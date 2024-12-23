#include <bits/stdc++.h>

using namespace std;

const int S = 2e5 + 1;
int v[S];
int main(){
    int n;
    
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        v[--x] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if(!v[i]){
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    
}