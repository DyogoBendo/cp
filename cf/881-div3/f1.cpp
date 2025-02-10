#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t){
        t --;

        int n;
        vector<vector<pair<int, int>>> graph;

        for(int i = 0; i < n; i++){
            int a, b, k;
            char c;
            cin >> c >> a >> b;
            if(c == '+'){
                a --;
                graph[a].push_back({graph.size(), b});
                graph.push_back(vector<pair<int, int>>(1, {a, b}));
            } else{
                cin >> k;
                    
            }
        }

    }
}