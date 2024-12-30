#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll v, a, b, c, x, res = INT32_MAX;
    cin >> v;
    for (ll i = 1; i <= sqrt(v); i++)
    {
        a = i;
        if(v % a) continue;
        x = v/a;
        for (ll j = 1; j <= sqrt(x); j++)
        {
            ll aux;
            if(x % j == 0){
                b = j;
                c = x/j;
            }
            aux = 2*(a*b + a*c + b*c);
            res = min(res, aux);
        }
    }
    
    cout << res << endl;
}