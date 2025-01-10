#include <bits/stdc++.h>

using namespace std;

class Cow{
    public:
        char d;
        int x, y;
};

class Crossing{
    public:
        int distance, stoppedCow, responsibleCow, responsibleCowDistance;
};

int dfs(vector<int> &visited, vector<vector<int>> &graph, vector<int> &ans, int curr){
    if(visited[curr]) return 0;
    visited[curr] = 1;

    int total = 0;

    for (auto e : graph[curr])
    {
        total += 1 + dfs(visited, graph, ans, e);
    }
    ans[curr] = total;
    
    return total;
}

int main(){
    int n;
    cin >> n;

    vector<Cow> cows(n);

    for (auto & c: cows) cin >> c.d >> c.x >> c.y;

    vector<Crossing> crossings;

    for (int i = 0; i < n; i++)
    {
        Cow c1 = cows[i];        
        for (int j = 0; j < n; j++)
        {
            Cow c2 = cows[j];
            Crossing cross;            
            int dy = c2.y - c1.y;
            int dx = c1.x - c2.x;

            if(c1.d == c2.d) continue;
            if(c1.d == 'E') continue;            
            if(c1.y > c2.y) continue;
            if(c2.x > c1.x) continue;
            if(dy == dx) continue;

            if(dy < dx){
                cross.distance = dx;
                cross.stoppedCow = j;
                cross.responsibleCow = i;
                cross.responsibleCowDistance = dy;
            } else{
                cross.distance = dy;
                cross.stoppedCow = i;
                cross.responsibleCow = j;
                cross.responsibleCowDistance = dx;
            }

            crossings.push_back(cross);
        }        
    }    
    
    sort(crossings.begin(), crossings.end(), [](const Crossing& c1, const Crossing &c2){return c1.distance < c2.distance;});
    
    vector<int> stopped(n, 0);    

    for (auto cross : crossings)
    {             
        if((stopped[cross.responsibleCow] && stopped[cross.responsibleCow] < cross.responsibleCowDistance) || stopped[cross.stoppedCow]) continue;
        stopped[cross.stoppedCow] = cross.distance;        
    }    

    for (int i = 0; i < n; i++)
    {
        if(!stopped[i]){
            cout << "Infinity" << endl;
        } else{
            cout << stopped[i] << endl;
        }
    }
    
}