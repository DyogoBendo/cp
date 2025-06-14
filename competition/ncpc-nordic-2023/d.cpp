#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)a.size())


void solve(){
    vector<int> v[3];

    for (int i = 0; i < 3; i++)
    {
        v[i] = vector<int>(6);

        for (int j = 0; j < 6; j++)
        {
            cin >> v[i][j];
        }
    }

    int ans = -1;
    for (int i = 0; i < 3; i++)
    {
        bool possible= true;
        for (int j = 0; j < 3; j++)
        {
            if(i == j) continue;

            int total = 0;
            int favor = 0;
            for (int a = 0; a < 6; a++)
            {
                for (int b = 0; b < 6; b++)
                {
                    if(v[i][a] == v[j][b]) continue;

                    total ++;
                    if(v[i][a] > v[j][b]) favor++;
                }
            }
            if(!favor or 2*favor < total) possible = false;
        }
        
        if(possible){
            ans = i;
            break;
        }
    }
    
    if(ans != -1){
        cout << ans +1 << endl;
    } else{
        cout << "No dice" << endl;
    }
}

signed main(){
    fastio;
    int t=1;
    // cin >> t;
    for (int i=0; i<t; i++) solve();
}