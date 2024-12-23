#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("wormsort");

    int n, m;
    cin >> n >> m;

    vector<int> cows(n);
    for (auto &c : cows)
    {
        cin >> c;
        c--;
    }

    int maxc = 0;    
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        

        graph[a].push_back({b, c});        
        graph[b].push_back({a, c});        

        maxc = max(maxc, c);
    }

    

    int lo = 0;
    int hi = maxc + 2;

    
    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;               

        vector<int> component(n, -1);
        stack<int> s;
        int count = 0;
        for (int i = 0; i < n; i++)
        {                    
            s.push(i);
            while(!s.empty()){                
                int curr = s.top();
                s.pop();                
                if(component[curr] != -1) continue;
                component[curr] = count;
                for (auto v : graph[curr])
                {
                    if(component[v.first] == -1 && v.second >= mid){
                        s.push(v.first);                        
                    }
                }
            }                    
            count ++;
        }

        bool possible = true;

        for (int i = 0; i < n; i++)
        {
            if(component[i] != component[cows[i]]) possible = false;
        }
        

        if(possible) lo = mid + 1;
        else hi = mid;

    }
    lo --;


    if(lo == maxc  + 1) cout << -1 << endl;
    else cout << lo << endl;
    
}