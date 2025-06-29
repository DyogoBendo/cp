#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define lld long double

const lld PI = acos(-1);

lld shoelace(pair<lld, lld> p1, pair<lld, lld> p2 ){
    return abs(p1.first * p2.second - p1.second * p2.first);
}

lld dist(pair<lld, lld> p1, pair<lld, lld> p2 ){
    lld dx = abs(p1.first - p2.first);
    lld dy = abs(p1.second - p2.second);    
    return sqrt(dx * dx + dy * dy);
}

lld calc2(pair<lld, lld> p1, pair<lld, lld> p2 ){
    lld s = (1e3 + 1e3 + dist(p1, p2) )/ 2;
    return sqrt((s - 1e3)*(s - 1e3)*(s - dist(p1, p2)) * s);
}

lld area(pair<lld, lld> p1, pair<lld, lld> p2 ){    
    lld dx = abs(p1.first - p2.first);
    lld dy = abs(p1.second - p2.second);        
    return ((dy) * (dx)) / 2;
}

lld cross(pair<lld, lld> p1, pair<lld, lld> p2){
    return p1.first * p2.second - p1.second*p2.first;
}

lld area_triangle(pair<lld, lld> p1, pair<lld, lld> p2, pair<lld, lld> p3){
    return fabs(cross({p2.first - p1.first, p2.second - p1.second}, {p3.first - p1.first, p3.second - p1.second})) / 2;
}

signed main(){
    darvem;
    cout << fixed << setprecision(18);

    int n, p;
    cin >> n >> p;

    vector<pair<lld, lld>> points(2*n);
    for (int i = 0; i < n; i++)
    {
        lld degree;
        cin >> degree;           

        lld x = cos(degree * PI / 180.0) * 1000.0;
        lld y = sin(degree * PI / 180.0) * 1000.0;

        points[i] = points[n + i] = {x, y};           
    }

    lld ans = 0;
    for (int st = 0; st < n; st++)
    {
        vector<vector<lld>> dp(p+1, vector<lld>(n, 0));        
                      
        for (int sz = 2; sz < p; sz++)
        {            
            for (int i = 1; i < n; i++)
            {                                                                                
                for (int j = 0; j < i; j++)
                {                                                                                       
                    dp[sz][i] = max(dp[sz - 1][j] + area_triangle(points[0], points[j], points[i]), dp[sz][i]);  
                    ans = max(ans, dp[sz][i]);
                }                                      
            }                                    
        }   
        rotate(points.begin(), points.begin() + 1, points.end());                           
    }
            
    cout << ans<< endl;
}