#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    v[n-1] = n;
    v[n-2] = n-1;

    if(n % 2 == 0){
        int cnt = 1;
        for (int i = n-3; i >= 0; i--)
        {
            v[i] = cnt;
            cnt++;
        }
    } else{
        v[0] = 1;
        v[1] = 2;
        v[2] = 3;
        int cnt = 4;
        for (int i = n-3; i >= 3; i--)
        {
            v[i] = cnt;
            cnt++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    
    cout << endl;

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}