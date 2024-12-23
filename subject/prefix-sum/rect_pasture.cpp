#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    int n;
    int x, y;
    cin >> n;    

    vector<vector<int>> ps(n + 1, vector<int>(n + 1, 0));
    vector<pair<int, int>> cows_coord;    
    vector<vector<int>> cows(n, vector<int>(n, 0));
    vector<int> tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;        
        cows_coord.push_back({x, y});
    }    

    sort(cows_coord.begin(), cows_coord.end());

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if(cows_coord[i].second > cows_coord[j].second) count ++;
        }
        tmp.push_back(count);
        cows[i][count] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ps[i][j] = cows[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];            
        }
        
    }

    long long ans = n + 1;


    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int y1, y2;
            y1 = tmp[i];
            y2 = tmp[j];
                        
            int smallest = min(y1, y2);
            int biggest = max(y1, y2);
            int top = 1 + ps[i][biggest + 1] - ps[i][smallest];            
            int bot = 1 + ps[n][biggest + 1] - ps[j + 1][biggest + 1] - ps[n][smallest] + ps[j + 1][smallest];
            ans += top * bot;
        }
        
    }
    
    
    cout << ans << endl;
}