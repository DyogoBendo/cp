#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int d;
    cin >> d;

    while(d--){
        int n;
        cin >> n;

        vector<int> v(n), v2;
        for(int i = 0; i < n; i++) cin >> v[i];

        v2 = v;
        sort(v.rbegin(), v.rend());

        int cnt = 0;
        for(int i = 0; i < n; i++)cnt+= v[i] == v2[i];
        cout << cnt << endl;
    }
}   