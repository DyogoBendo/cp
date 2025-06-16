#include <bits/stdc++.h>

using namespace std;

int main(){
    int xi, yi, xf, yf, n;
    
    cin >> xi >> yi >> xf >> yf;

    cin >> n;

    vector<tuple<int, int, int, int>> blocos;

    for (int i = 0; i < n; i++)
    {
        int x0, y0, x, y;
        cin >> x0 >> y0 >> x >> y;

        blocos.push_back({x0, y0, x, y});
    }


    vector<vector<int>> graph(n + 2, vector<int>(n + 2, 0));

    for (int i = 0; i < n; i++)
    {
        int dx = 0, dy = 0;

        const auto [x0, y0, x, y] = blocos[i];

        if(xi > x) dx = xi - x;
        else if(xi < x0) dx = x0 - xi;

        if(yi > y) dy = dy = yi - y;
        else if (yi < y0) dy = y0 - yi;        

        graph[0][i + 1] = dx + dy;
    }

    
    for (int i = 0; i < n; i++)
    {
        int dx = 0, dy = 0;

        const auto [x0, y0, x, y] = blocos[i];

        if(xf > x) dx = xf - x;
        else if(xf < x0) dx = x0 - xf;

        if(yf > y) dy = dy = yf - y;
        else if (yf < y0) dy = y0 - yf;

        graph[i + 1][n + 1] = dx + dy;
    }

    graph[0][n + 1] = abs(xf - xi) + abs(yf - yi);    
    

    for (int i = 0; i < n; i++)
    {

        const auto [x1, y1, x2, y2] = blocos[i];

        for (int j = i + 1; j < n; j++)
        {
            int dx = 0, dy = 0;
            const auto [x3, y3, x4, y4] = blocos[j];
            if(x2 < x3 ) dx = x3 - x2;
            else if(x4 < x1) dx = x1 - x4;

            if(y2 < y3 ) dy = y3 - y2;
            else if(y4 < y1) dy = y1 - y4;

            graph[i + 1][j + 1] = dx + dy;
            graph[j + 1][i + 1] = dx + dy;
        }        
    }

    priority_queue<pair<int, int>> pq;
    
    vector<int>distance(n + 2, -1);
    distance[0] = 0;

    for (int i = 1; i < n + 2; i++)
    {
        pq.push({-graph[0][i], i});        
    }

    while(distance[n + 1] == -1){
        auto p = pq.top(); pq.pop();

        int d = -p.first;
        int e = p.second;        

        if(distance[e] == -1){
            distance[e] = d;

            for (int j = 1; j < n + 2; j++)
            {
                if(distance[j] == -1){                                        
                     pq.push({-(d + graph[e][j]), j });
                }
            }
            
        }

    }

    cout << distance[n + 1] << endl;
    
}