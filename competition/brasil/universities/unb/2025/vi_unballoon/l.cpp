#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
int a, b, c;

int calc(int x){

    int p3 = (a+c) *x *x*x;
    int p2 = (-b) * x*x;
    int p1 = (b*c) *x;
    int p0 = (x+c) * (x - a);

    return abs(p3 + p2 + p1 + p0);
}

signed main(){
    darvem;
    cin >> a >> b >> c;

    int q;
    cin >> q;
    int ans = 0;
    while(q--){
        int x;
        cin >> x;
        ans ^= calc(x);
    }

    cout << ans << endl;
}