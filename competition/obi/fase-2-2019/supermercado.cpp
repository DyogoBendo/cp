#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    double ans = 10000;
    for (int i = 0; i < n; i++)
    {
        double p, g;
        cin >> p >> g;        
        ans = min(ans, p/g);
    }

    printf("%.2lf\n", ans * 1000);
    
}