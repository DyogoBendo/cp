// https://usaco.org/index.php?page=viewproblem2&cpid=1015

#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

#define int long long
const int MOD = 1e9 + 7;

class Point{
    public: 
    int x, y, xSum, ySum, id;        
};

bool compX(const Point& p1, const Point&p2){
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}
bool compY(const Point& p1, const Point&p2){
    if(p1.y == p2.y) return p1.x < p2.x;
    return p1.y < p2.y;
}

int getX(const Point& p){
    return p.x;
}
int getY(const Point& p){
    return p.y;
}

void setSumX(Point &p, int sum){
    p.xSum = sum;
}

void setSumY(Point &p, int sum){
    p.ySum = sum;
}

signed main(){
    setIO("triangles");

    int n;
    cin >> n;
    vector<Point> v(n);

    map<int, vector<Point>> yLines; // points that belong to a line parallel to the y axis
    map<int, vector<Point>> xLines; // points that belong to a line parallel to the x axis

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y;
        v[i].xSum = 0;
        v[i].ySum = 0;
        v[i].id = i;

        yLines[v[i].x].push_back(v[i]);
        xLines[v[i].y].push_back(v[i]);
    }

    auto addLine = [&](map<int, vector<Point>> &lineMap, function<bool(Point&, Point&)> comp, function<int(Point&)> get, function<void(Point&, int)> setSum){
        for (auto &line : lineMap)
        {
            vector<Point> points= line.second;            
            int sz = points.size();

            if(sz <= 1) continue;

            sort(points.begin(), points.end(), comp);  

            int s = 0;         
            for (int i = 1; i < sz; i++)
            {
                s += get(points[i]) - get(points[0]);
            }
            setSum(v[points[0].id], s);

            for (int i = 1; i < sz; i++)
            {                
                s += (2*i - sz) * (get(points[i]) - get(points[i - 1]));
                s %= MOD;
                setSum(v[points[i].id], s);
            }                        
        }        
    };
    
    addLine(yLines, compY, getY, setSumY);
    addLine(xLines, compX, getX, setSumX);
    
    int ans = 0;
    for (auto p : v)
    {        
        ans += p.xSum * p.ySum;
        ans %= MOD;
    }

    cout << ans << endl;
    

}