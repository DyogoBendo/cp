#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    int n, h;
    cin >> n >> h;

    int cnt= 0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if(a <= h) cnt++;
    }

    cout << cnt << endl;

}