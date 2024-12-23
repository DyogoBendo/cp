#include <bits/stdc++.h>

using namespace std;

int d[61];
int e[61];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        char p;
        cin >> t >> p;
        if(p == 'D') d[t] ++;
        else e[t]++;
    }

    int ans = 0;
    for (int i = 0; i < 61; i++)
    {
        ans += min(d[i], e[i]);
    }
    
    cout << ans << endl;
    
}