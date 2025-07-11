#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int INF = 1e9;

int dx[] = {1, -1, 1, -1};
int dy[] = {1, 1, -1, -1};

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<pair<int, int>> ans;
    int tot = 4;
    for (int i = 0; i < 4; i++)
    {

        int curr = -INF, x, y;
        for (int j = 0; j < n; j++)
        {
            if(v[j].first*dx[i] + v[j].second*dy[i] > curr){
                curr = max(curr, v[j].first*dx[i] + v[j].second*dy[i]);
                x = v[j].first, y = v[j].second;
            }
        }            
        tot += curr;
        ans.push_back({x, y});
    }    

    bool d1 = true, d2 = true;;

    for (int i = 1; i < n; i++)
    {
        if(v[i].first - v[0].first != v[i].second -  v[0].second) d1 = false;                
        if(v[i].first - v[0].first != -(v[i].second -  v[0].second)) d2 = false;
    }
    
    if((d1 or d2) && n > 1){        
        tot++;
    } 
    
    cout << tot << endl;
}