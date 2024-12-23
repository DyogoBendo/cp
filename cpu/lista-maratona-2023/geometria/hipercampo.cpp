#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> points;
vector<int> dp;

// clockwise
bool cw(int a, int b, int c){
    return ((points[c].first-points[a].first)*(points[b].second-points[a].second) < (points[b].first-points[a].first)*(points[c].second-points[a].second));
}

bool inside(int pt, int tri){
    return cw(0, tri, pt) && cw(tri, 1, pt) && cw(1, 0, pt);
}

int main(){
    int n, xa, xb;
    cin >> n >> xa >> xb;
    points.push_back({0, xa});
    points.push_back({0, xb});

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        points.push_back({b, a});
    }

    sort(points.begin(), points.end());

    int resp = 0;    

    for (int i = 2; i < n + 2; i++)
    {        
        dp.push_back(1);
        for (int j = 2; j < i; j++)
        {
            if(inside(j, i)){
                dp[i - 2] = max(dp[i - 2], dp[j - 2] + 1);
            }
        }
        resp = max(resp, dp[i - 2]);
    }
    
    cout << resp << endl;
        
}