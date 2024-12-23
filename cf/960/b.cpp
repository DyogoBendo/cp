#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n, x, y;

    cin >> n >> x >> y;
    vector<int> v (n);

    x --;
    y --;    

    for (int i = y; i <= x; i++)
    {
        v[i] = 1;
    }

    int c = -1;
    for (int i = y - 1; i >= 0; i--)
    {
        v[i] = c;
        c *= -1;
    }

    c = -1;
    for (int i = x + 1; i < n; i++)
    {
        v[i] = c;
        c *= -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}