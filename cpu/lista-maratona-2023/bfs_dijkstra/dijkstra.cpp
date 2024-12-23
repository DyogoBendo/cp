#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t){
        t --;
        int k, v;
        cin >> v >> k;
        vector<vector<pair<int, int>>> graph;
        for (int i = 0; i < v; i++) graph.push_back(vector<pair<int, int>>());

        for (int i = 0; i < k; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a --;
            b --;
            graph[a].push_back(make_pair(b, c));            
        }        

        int startV, endV;
        cin >> startV >> endV;

        startV --;
        endV --;
        vector<pair<int, int>> h;        
        vector<int> cost(v);
        vector<int> visited(v);
        
        for(int i = 0; i < v; i++) cost[i] = -1;
        cost[startV] = 0;        

        h.push_back(make_pair(0, startV));        

        while(!h.empty()){
            pop_heap(h.begin(), h.end());
            auto current = h.back();
            h.pop_back();         
            
            int currentCost = -current.first;
            int currentVertice = current.second;   
            if(visited[currentVertice]) continue;
            visited[currentVertice] = 1;

            for (auto e : graph[currentVertice])
            {                
                if(!visited[e.first]){
                    int nextCost = currentCost + e.second;
                    if(cost[e.first] == -1){
                        cost[e.first] = nextCost;
                    } else{                        
                        cost[e.first] = min(nextCost, cost[e.first]);
                    }
                    
                    h.push_back(make_pair(-nextCost, e.first));
                    push_heap(h.begin(), h.end());
                }
            }            
        }
        if(cost[endV] == - 1){
            cout << "NO" << endl;
        } else{
            cout << cost[endV] << endl;
        }
    }
}