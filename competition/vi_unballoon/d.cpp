#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    int rl, hl, rc, hc;
    cin >> rl >> hl >> rc >> hc;

    if((3*rl*rl*hl) > (2 * rc * rc * rc) + (rc*rc*hc)) cout << "Injusto";
    else cout << "Justo";
    cout << endl;
}