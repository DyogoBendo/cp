#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int len = 1; len <= n; len++)
    {
        if(n % len) continue;

        int possible = 1;
        int used = 0;
        
        for (int k = 0; k < len; k++)
        {
            int c[26] = {0};
            for (int i = k; i < n; i+= len)
            {
                c[s[i] - 'a'] ++;
            }
            
            int diff = 0;
            int m = n;
            for (auto v : c)
            {
                if(v){
                    m = min(m, v);
                    diff ++;
                }
            }
            if(diff > 2) possible = 0;
            if(diff == 2) used += m;

            if(!possible || used > 1) break;
        }

        if(used > 1) possible = 0;        
        
        if(possible){
            cout << len << endl;
            break;
        }
    }
    
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}