#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long

signed main(){
    int n, w;
    cin >> n >> w;

    vector<tuple<int, int, int>> waves;
    for (int i = 0; i < n; i++)
    {
        char o;
        cin >> o;

        if(o == '!'){
            int st, l, a;
            cin >> st >> l >>a;
            waves.push_back({st, l-1, a});
        } else{
            int p;
            cin >> p;

            int ans = 0;
            for (auto [st, l, a] : waves)
            {
                if(st > p) continue;
                if(st + l < p) continue;
                

                if(p % 4 == st % 4){
                    ans += a;
                } else if(p % 4 == (st + 2) % 4){
                    ans -= a;
                }
            }
            
            cout << ans << endl;
        }
    }
    
}