#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<bool> v(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        v[x - 1] = 1; 
    }

    int missing = 0;
    for (int i = 0; i < n; i++)
    {
        if(!v[i]) missing = i + 1;
    }
    
    cout << missing << endl;
    
}