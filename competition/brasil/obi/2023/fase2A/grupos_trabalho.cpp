#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int count_likes_out(int curr, vector<vector<int>> &likes, int a, int b){
    int total = likes[curr].size();

    for (auto e : likes[curr])
    {
        if(e == a || e == b) total --;
    }
    
    return total;
}

int count_hates_in(int curr, vector<vector<int>> &hates, int a, int b){
    int total = 0;

    for (auto e : hates[curr])
    {
        if(e == a || e == b) total ++;
    }    
    return total;
}

void solve(){
    int e, m, d, ans =0;
    cin >> e >> m >> d;

    vector<vector<int>> hate(e);
    vector<vector<int>> like(e);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;y--;
        like[x].push_back(y);
        like[y].push_back(x);
    }
    
    for (int i = 0; i < d; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;y--;
        hate[x].push_back(y);
        hate[y].push_back(x);
    }
    
    for (int i = 0; i < e/3; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;c--;        

        int total_likes = count_likes_out(a, like, b, c) + count_likes_out(b, like, a, c) + count_likes_out(c, like, b, a);
        int total_hates = (count_hates_in(a, hate, b, c) + count_hates_in(b, hate, a, c) + count_hates_in(c, hate, b, a)) ;

        ans += total_likes + total_hates;
    }
    
    cout << ans / 2 << endl;
}

signed main(){
    flash;
    solve();
}