#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define int long long

signed main(){
    ld d, a, o, da, doo;
    cin >> d >> a >> o >> da >> doo;

    ld calcVa = da * d, calcVo = doo * d;

    ld finalA = a - calcVa;
    ld finalO = o - calcVo;

    if(finalA < 0) finalA = 0;
    if(finalO < 0) finalO = 0;

    cout << setprecision(12) << fixed;
    if(finalA == 0) cout << 0 << endl;
    else if(finalO == 0) cout << 100 << endl;
    else {
        ld tot = finalA + finalO;
        ld ans = ((ld) finalA) / ((ld) tot);
        cout << ans*100 << endl;
    }
}