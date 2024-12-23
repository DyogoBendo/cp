#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>v(n);

    int t = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        t += v[i];
    }
    t /= n;

    for (int i = 0; i < n; i++)
    {
        cout << t - v[i] << endl;
    }
    
    
    
}