#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long


signed main(){
    int n, m, k;
    cin >> n >> m >> k;
   
    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
    }

    sort(v.rbegin(), v.rend());

    double curr= 0;

    for (int i = 0; i < min(n, m+k); i++)
    {
        curr += v[i];
    }
    
    printf("%.20lf\n", (curr / total) * 100);
    
}