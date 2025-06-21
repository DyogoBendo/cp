#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, s;
    cin >> n >> s;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x, y, dx, dy;
        cin >> dx >> dy >> x >> y;

        bool acha = false;
        for (int i = 0; i < 4; i++)
        {            
            if(dx > 0 && dy > 0){
                int mov = s - max(x, y);
                x += mov;
                y += mov;

                if(x == s && y ==s){
                    acha= true;
                    break;
                } 

                if(x == s){
                    dx = -1;
                } else{
                    dy = -1;
                }

            } else if(dx > 0 && dy < 0){
                int mov = min(y, s - x);
                x += mov;
                y -= mov;

                if(x == s && y ==0){
                    acha= true;
                    break;
                } 

                if(x == s){
                    dx = -1;
                } else{
                    dy = 1;
                }
            } else if(dx < 0 && dy > 0){
                int mov = min(x, s - y);
                x -= mov;
                y += mov;

                if(x == 0 && y ==s){
                    acha= true;
                    break;
                } 

                if(x == s){
                    dx = 1;
                } else{
                    dy = -1;
                }
            } else{
                int mov = min(x, y);
                x -= mov;
                y -= mov;

                if(x == 0 && y ==0){
                    acha= true;
                    break;
                } 

                if(x == s){
                    dx = 1;
                } else{
                    dy = 1;
                }
            }
        }
        ans += acha;
    }

    cout << ans << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}