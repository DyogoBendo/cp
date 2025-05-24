#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        ans++;
        int x = s[i+1] - s[i];
        if(x <= 0){
            ans += s[i] - s[i+1];
        } else{
            ans += 10 - x;
        }
    }
    ans++;
    ans += s.back() - '0';
    cout << ans << endl;    
}