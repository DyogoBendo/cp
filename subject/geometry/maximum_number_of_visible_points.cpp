#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const double PI = acos(-1);

int solve(vector<vector<int>>& points, int angle, vector<int>& location){
    
    double dang = (PI * angle / 180); 
    
    vector<double> angles;
    int extra = 0;
    for (int i = 0; i < (int) points.size(); i++)
    {
        if(points[i] == location){
            extra ++; continue;
        }
        double ang = atan2(points[i][1] - location[1], points[i][0] - location[0]);
        angles.push_back(ang);
    }
    
    int n = angles.size();
    sort(angles.begin(), angles.end());

    for (int i = 0; i < n; i++)
    {
        angles.push_back(angles[i] + 2 * PI);
    }
    
    int l = 0, ans = 0;
    for (int i = 0; i < 2*n; i++)
    {
        while(angles[i] > angles[l] + dang)l ++;        
        ans = max({ans, i - l + 1});
    }
    
    return ans + extra;
}

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> points;

    for (int i = 0; i < n; i++)
    {
        vector<int> p;
        for (int j = 0; j < 2; j++)
        {
            int x;
            cin >> x;
            p.push_back(x);
        }
        points.push_back(p);        
    }

    int a;
    cin >> a;

    vector<int> location;
    for (int i = 0; i < 2; i++)
    {
        int x;
        cin >> x;
        location.push_back(x);
    }
    

    cout << solve(points, a, location) << endl;
}