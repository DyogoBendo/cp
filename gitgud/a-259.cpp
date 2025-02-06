// https://codeforces.com/contest/453/problem/A

#include <bits/stdc++.h>

using namespace std;

#define lld long double

int main(){
    lld m, n;
    cin >> m >> n;    
    
    lld ans = 0;    

    
    for (lld i = 1; i <= m; i++)
    {
        ans += (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n)) * i;
    }    

    printf("%.12Lf\n", ans);
}