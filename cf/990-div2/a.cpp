#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }    

    int x = 1;
    int ans = 0;
    int total = 1;    
    int curr = 0;

    set<int> odd_squares;

    for (int i = 1; i < 1000; i+=2)
    {
        odd_squares.insert(i * i);
    }
    

    for (int i = 0; i < n; i++)
    {
        curr += v[i];
        if(odd_squares.find(curr) != odd_squares.end()) ans ++;
    }
    
    cout << ans << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}