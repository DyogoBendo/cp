#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};


int maxPoints(vector<vector<int>> & points){
    int n = (int) points.size();
    vector<pt> pts(n);

    for (int i = 0; i < n; i++)
    {
        pts[i] = pt(points[i][0], points[i][1]);
    }
    
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cnt = 2;
            for (int k = j + 1; k < n; k++)
            {
                ll area =(pts[j] - pts[i]) ^ (pts[k] - pts[j]);                
                if(area == 0) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    
    return ans;
}

signed main(){
    darvem;

    vector<vector<int>> test = {{1, 1}, {3, 2}, {5,3}, {4, 1}, {2, 3}, {1, 4}};

    cout << maxPoints(test) << endl;
}