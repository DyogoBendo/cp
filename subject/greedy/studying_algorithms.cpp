#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int current = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        current += a[i];
        if(current > x) break;
        ans ++;
    }
        
    cout << ans << endl;
}