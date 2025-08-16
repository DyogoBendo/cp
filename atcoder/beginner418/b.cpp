#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    string s;
    cin >> s;
    int n = s.size();

    double ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != 't') continue;
        for(int j = i+2; j < n; j++){            
            if(s[j] != 't') continue;
            int cnt = 0;
            for(int k = i + 1; k < j; k++){
                cnt += s[k] == 't';
            }            
            ans = max(ans, (cnt) / (j - i -1.0));
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
}