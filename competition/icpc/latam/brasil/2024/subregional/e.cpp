#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    int n;
    cin >> n;

    int smallest = 2e5, x = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int e;
            cin >> e;

            if(e < smallest){
                x = i, y = j;
                smallest = e;
            }
        }        
    }

    if(x == 0){
        if(y == 0) cout << 0 << endl;
        if(y == n-1) cout << 1 << endl;   
    } else{
        if(y == 0) cout << 3 << endl;
        if(y == n-1) cout << 2 << endl;   
    }
    
}