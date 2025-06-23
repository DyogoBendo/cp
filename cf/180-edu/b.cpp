#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        if(abs(v[i] - v[i + 1]) <= 1){
            cout << 0 << endl;
            return;
        }
    }

    int increasing = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if(v[i] < v[i+1]){
            if(increasing == -1){
                cout << 1 << endl;
                return;
            }
            increasing = 1;
        } else if(v[i] > v[i+1]){
            if(increasing == 1){
                cout <<1 << endl; 
                return;
            }
            increasing = -1;
        }
    }
    
    cout << "-1" << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}