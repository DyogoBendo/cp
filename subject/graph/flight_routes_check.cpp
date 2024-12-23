#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graphA;
vector<vector<int>> graphB;
vector<int> visited;

int dfsA(int curr){
    if(visited[curr]) return 0;

    visited[curr] = 1;
    int c = 1;
    for (auto v : graphA[curr])
    {
        c += dfsA(v);
    }
    
    return c;
}

int dfsB(int curr){
    if(visited[curr]) return 0;

    visited[curr] = 1;
    int c = 1;
    for (auto v : graphB[curr])
    {
        c += dfsB(v);
    }
    
    return c;
}

int main(){
    int n, m;
    cin >> n >> m;

    graphA.resize(n);
    graphB.resize(n);
    visited.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graphA[a].push_back(b);
        graphB[b].push_back(a);        
    }

    bool a = dfsA(0) == n;

    if(!a){
        for (int i = 0; i < n; i++)
        {
            if(!visited[i]){
                cout << "NO" << endl;
                cout << 1 << " " << i + 1 << endl;
                break;
            }
        }
        
    } else{
        fill(visited.begin(), visited.end(), 0);
        bool b = dfsB(0) == n;
        if(!b){
            for (int i = 0; i < n; i++)
            {
                if(!visited[i]){
                    cout << "NO" << endl;
                    cout << i + 1 << " " << 1 << endl;
                    break;
                }
            }   
        } else{
            cout << "YES" << endl;
        }
    }



    
}