#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)((a).size()))
#define ld long long double

const double PI = acos(-1);

double arc(){return PI * 5 / 2.0;}


void solve(){
    int h, w;
    cin >> h >> w;

    vector<vector<char>> buildings(h, vector<char>(w));

    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> buildings[i][j];

    vector<vector<vector<tuple<int, int, double>>>> graph(2*h+1, vector<vector<tuple<int, int, double>>>(2*w+1));

    for(int i = 0; i <= 2*h; i++){
        for(int j = 0; j <= 2*w; j++){
            if(i %2 && j % 2) continue;
            if(i < 2*h){
                if(!((i+1)%2 && j%2)) graph[i][j].push_back({i + 1, j, 5});
                if(i % 2 == 1){
                    if(i/2 < h && j/2 < w && buildings[i/2][j/2] == 'O'){
                        graph[i][j].push_back({i + 1, j + 1, arc()});
                        graph[i][j].push_back({i-1, j+1, arc()});
                    }
                    graph[i][j].push_back({});
                }
            }

            if(j < 2*w){
                if(!((j+1) % 2 && i % 2)) graph[i][j].push_back({i, j+1, 5});
                if(j % 2 == 1){
                    if(i/2 < h && j/2 < w && buildings[i/2][j/2] == 'O'){
                        graph[i][j].push_back({i + 1, j + 1, arc()});
                        graph[i][j].push_back({i+1, j-1, arc()});
                    }
                    graph[i][j].push_back({});
                }
            }            
        }
    }

    priority_queue<tuple<double, int, int>> pq;

    pq.push({0, 0, 0});

    vector<vector<double>> dist(2*h+1, vector<double>(2*w+1));
    vector<vector<int>> visited(2*h+1, vector<int>(2*w+1));

    while(!pq.empty()){
        auto [d, x, y] = pq.top(); pq.pop();

        if(visited[x][y]) continue;
        d= -d;

        dist[x][y] = d;
        visited[x][y] = 1;

        for(auto [a, b, w] : graph[x][y]){
            if(!visited[a][b]){
                pq.push({-(w+d), a, b});
            }
        }
    }

    cout << setprecision(12) << fixed << dist[2*h][2*w] << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}