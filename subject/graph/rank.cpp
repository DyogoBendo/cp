#include <bits/stdc++.h>

using namespace std;

int graph[20][20];
int visited[20];
int cyclic[20];

void dfs(int curr, vector<int> v){
    if(!visited[curr]){
        visited[curr] = 1;
        v.push_back(curr);
        for (int i = 0; i < 20; i++)
        {        

            if(graph[curr][i]){
                for (auto prev: v)
                {
                    if(i == prev){
                        for (auto t : v)
                        {
                            cyclic[t] = 1;
                        }
                        
                    }
                }

                dfs(i, v);
            }
            
            
        }
        
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        a--;
        b--;

        if(sa > sb){
            graph[a][b] = 1;
        } else{
            graph[b][a] = 1;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]) dfs(i, vector<int>());
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(cyclic[i]) ans ++;
    }
    
    cout << ans << endl;
}