#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool print = false;
            if(i == 0 || i == n-1) print = true; 
            if(j == 0 || j == n - 1) print = true;
            if(i == j) print = true;
            if(i + j == n - 1) print = true;

            cout << (print? "*" : " ");
        }
        cout << endl;
    }
    
}