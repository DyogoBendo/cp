#include <bits/stdc++.h>

using namespace std;

const long long MAX_V = 1e10;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> components(n, 0);
    int current = 1;
    for (int i = 0; i < n; i++)
    {
        stack<int> s;
        s.push(i);
        while(!s.empty()){
            int c = s.top();
            s.pop();

            if(components[c]) continue;               
            components[c] = current;

            for (auto v : graph[c]){                
                s.push(v);
            }
            
        }          
        current ++;
    }    

    vector<long long> first_distance(current, MAX_V);
    vector<long long> last_distance(current, MAX_V);

    int curr_l_first = -1;
    int curr_l_last = -1;

    for (int i = 0; i < n; i++)
    {
        int c = components[i];
        if(c == 1){
            curr_l_first = i;
        }
        if(c == components[n - 1]){
            curr_l_last = i;
        }
        
        if(curr_l_first != -1){
            long long dst_first = (i - curr_l_first);
            first_distance[c] = min(dst_first * dst_first, first_distance[c]);
        }

        if(curr_l_last != -1){
            long long dst_last = (i - curr_l_last);
            last_distance[c] = min(dst_last * dst_last, last_distance[c]);      
        }

    }
    
    curr_l_first = -1;
    curr_l_last = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        int c = components[i];
        if(c == 1){
            curr_l_first = i;
        }
        if(c == components[n - 1]){
            curr_l_last = i;
        }
        
        if(curr_l_first != -1){
            long long dst_first = (i - curr_l_first);
            first_distance[c] = min(dst_first * dst_first, first_distance[c]);
        }

        if(curr_l_last != -1){
            long long dst_last = (i - curr_l_last);
            last_distance[c] = min(dst_last * dst_last, last_distance[c]);      
        }

    }
    

    long long ans = MAX_V;

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, first_distance[i] + last_distance[i]);
    }
    
    cout << ans << endl;
    
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();    
    
}