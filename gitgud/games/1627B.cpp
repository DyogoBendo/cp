#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    queue<tuple<int, int, int, int>> q;
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));

    int middle_n = n / 2;
    int middle_m = m / 2;
    int odd_n = n % 2;
    int odd_m = m % 2;
    int mi = n - (middle_n + odd_n) + m - (middle_m + odd_m);

    q.push({middle_n + odd_n, middle_m + odd_m, mi, 0});
    if(!odd_n){
        q.push({middle_n + 1, middle_m + odd_m, mi, 0});

    }
    if(!odd_m){
        q.push({middle_n + odd_n, middle_m + 1, mi, 0});
    }
    if(!odd_m && !odd_n){
        q.push({middle_n + 1, middle_m + 1, mi, 0});
    }

    vector<int> ans;
    vector<int> qtd;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        int row = get<0>(curr);
        int column = get<1>(curr);
        int x = get<2>(curr);
        int level = get<3>(curr);
        if(visited[row][column]) continue;
        visited[row][column] = 1;
        // cout << "row: " << row << " column: " << column << " x: " << x << " level: " << level << endl;

        if(ans.size() == level){
            ans.push_back(x);
            qtd.push_back(1);
        } else{
            qtd[level] ++;
        }

        if(row < n){
            q.push({row + 1, column, x + 1, level + 1});
        }
        if(row > 1){
            q.push({row - 1, column, x + 1, level + 1});
        }
        if(column < m) q.push({row, column + 1, x + 1, level + 1});
        if(column > 1) q.push({row, column - 1, x + 1, level + 1});        
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < qtd[i]; j++)
        {
            cout << ans[i] << " ";
        }        
    }
    

    cout << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}