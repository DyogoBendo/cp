#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long double w;
    cin >> n >> w;

    vector<pair<long double, long double>> v(n);

    for (int i = 0; i < n; i++)
    {
        long double a, b;
        cin >> a >> b;
        v[i] = {b / a, a};
    }


    sort(v.begin(), v.end());

    
    int k = n - 1;
    long double ans = 0;
    while(w > 0 && k >= 0){
        long double subtract = min(w, v[k].second);
        w -= subtract;
        ans += v[k].first * subtract;
        k --;
    }

    printf("%.2Lf\n", ans);
            
}