#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >>m;

    string s, t;
    cin >> s >> t;

    vector<int> pxor(n+1);

    while(m--){
        int a, b;
        cin >> a >> b;

        a--;
        pxor[a]^=1;
        pxor[b]^=1;
    }

    int curr = 0;
    for(int i = 0; i < n; i++){
        curr ^= pxor[i];
        cout << (curr ? t[i] : s[i]);
    }
    cout << endl;

}