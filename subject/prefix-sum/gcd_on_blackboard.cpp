#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = v[0];
    suffix[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = __gcd(prefix[i - 1], v[i]);
    }
    for (int i =  n - 2; i >= 0; i--)
    {
        suffix[i] = __gcd(suffix[i + 1], v[i]);
    }
    
    
    int ans = max(suffix[1], prefix[n - 2]);
    for (int i = 1; i < n - 1; i++)
    {        
        ans = max(ans, __gcd(prefix[i - 1], suffix[i + 1]));
    }    
    
    cout << ans << endl;   
}