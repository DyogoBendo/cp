#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int INF = 1e9;

int main(){
    setIO("lasers");

    int n, xl, yl, xb, yb;
    cin >> n >> xl >> yl >> xb >> yb;

    vector<pair<int, int>> fences(n+2);    

    fences[0] = {xl, yl};
    fences[n+1] = {xb, yb};

    vector<int> up(n+2, -1), right(n+2, -1), left(n+2, -1), down(n+2, -1);    

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        fences[i] = {x, y};
    }
    
    map<int, vector<pair<int, int>>> same_x, same_y;
    for(int i = 0; i < n+2; i++){
        same_x[fences[i].first].push_back({fences[i].second, i});
        same_y[fences[i].second].push_back({fences[i].first, i});
    }
    
    for(auto [x, v] : same_x){
        sort(v.begin(), v.end());
                
        for(int i = 0; i < v.size() - 1; i++){
            up[v[i].second] = v[i+1].second;
        }           
        for(int i = v.size() - 1; i > 0; i--){
            down[v[i].second] = v[i-1].second;
        }           
    }
    
    for(auto [y, v] : same_y){
        sort(v.begin(), v.end());
                
        for(int i = 0; i < v.size() - 1; i++){
            right[v[i].second] = v[i+1].second;
        }   
        for(int i = v.size() - 1; i > 0; i--){
            left[v[i].second] = v[i-1].second;
        }           
    }
    
    
    auto solve = [&](){
        deque<tuple<int, int, int>> q;
        q.push_back({0, 0, 0});
        q.push_back({0, 0, 1});
        
        vector<vector<int>> visited(n+2, vector<int>(2, INF));

        while(!q.empty()){
            auto [curr, w, d] = q.front(); q.pop_front();              
            if(visited[curr][d] != INF) continue;

            visited[curr][d] = w;                 
            
            int r = right[curr];
            int u = up[curr];
            int l = left[curr];
            int b = down[curr];            

            if(r != -1){
                if(d == 0) q.push_front({r, w, d});             
                else q.push_back({r, w+1, d^1});                
            }

            if(l != -1){
                if(d == 0) q.push_front({l, w, d});             
                else q.push_back({l, w+1, d^1});                
            }

            if(u != -1){
                if(d == 1) q.push_front({u, w, d}); 
                else q.push_back({u, w+1, d^1});                 
            }

            if(b != -1){
                if(d == 1) q.push_front({b, w, d}); 
                else q.push_back({b, w+1, d^1});                 
            }

        }

        int bst = min(visited[n+1][0], visited[n+1][1]);
        if(bst == INF) bst = -1;
        return bst;
    };

    cout << solve() << endl;

}