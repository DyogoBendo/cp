    #include <bits/stdc++.h>

    using namespace std;

    #define int long long
    vector<vector<int>> connections;
    vector<tuple<int, int, int>> v;   
    vector<int> signals;
    bool possible = true;

    void dfs(vector<int> &visited, int curr, int signal){    
        if(visited[curr] ){                
            return;    
        }     
        visited[curr] = 1;
        signals[curr] = signal;
    
        for (auto u: connections[curr])
        {               
            dfs(visited, u, signal * (-1));
        }
    }

    signed main(){
        int n;
        cin >> n;     

        for (int i = 0; i < n; i++)
        {
            int x, y, r;
            cin >> x >> y >> r;

            v.push_back({x, y, r});
        }

        signals.resize(n);
        fill(signals.begin(), signals.end(), 0);
        connections.resize(n);


        for (int i = 0; i < n; i++)
        {
            int x = get<0>(v[i]);
            int y = get<1>(v[i]);
            int r = get<2>(v[i]);

            for (int j = i + 1; j < n; j++)
            {
                int x2 = get<0>(v[j]);
                int y2 = get<1>(v[j]);
                int r2 = get<2>(v[j]);

                int dr = r + r2;
                int dx = x - x2;
                int dy = y - y2;
                int d = (dx * dx) + (dy * dy);
                if(d == dr * dr){
                    connections[i].push_back(j);
                    connections[j].push_back(i);
                }
            }        
        }
        
        vector<int>visited(n, 0);
        dfs(visited, 0, 1);

        for (int i = 0; i < n; i++)
        {
            if( !visited[i]) continue;
            for (auto u : connections[i])
            {
                if(signals[u] == signals[i]) possible = false;
            }
            
        }        
        
        if(!possible){            
            cout << "The input gear cannot move." << endl;
        } 
        else if(!visited[n - 1]){        
            cout << "The input gear is not connected to the output gear." << endl;
        } else{                
                int r1 = get<2>(v[0]) ;
                int r2 = get<2>(v[n-1]);            
                int g = __gcd(r1, r2);

                cout << (r1 / g) * signals[n - 1] << ":" << r2 / g << endl;        
        }

    }