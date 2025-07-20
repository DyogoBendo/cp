#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double

struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ld dist2(pt p, pt q) { // quadrado da distancia
	return hypot(p.x - q.x, p.y - q.y);
}

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

int ccw(pt p, pt q, pt r){
    return sarea2(p, q, r) > 0;
}

vector<pt> convex_hull(vector<pt> pts) { // convex hull - O(n log(n))
	sort(pts.begin(), pts.end());  
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    if(pts.size() <= 1) return pts;        
    
    vector<pt> s, u;

    int n = pts.size();

    for(int i = 0; i < n; i++){            
        while(s.size() > 1 && !ccw(s.end()[-2], s.end()[-1], pts[i])){
            s.pop_back();                
        }            
        s.emplace_back(pts[i]);
    }                

    for(int i = n-1; i >= 0; i--){            
        while(u.size() > 1 && !ccw(u.end()[-2], u.end()[-1], pts[i])){
            u.pop_back();
        }        
        u.emplace_back(pts[i]);
    }
    u.pop_back(); s.pop_back();
    for(auto i : u) s.push_back(i);

    return s;
}

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pt> pts(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pts[i];
    }

    vector<pt> polygon = convex_hull(pts);
    
    ld ans = 0;

    int sz = polygon.size();
    for (int i = 0; i < sz; i++)
    {
        int x = (i + sz/2) % sz, x2 = (i + (sz-1) /2) % sz, x3 = (i + (sz+1) / 2) % sz;
        pt p = polygon[i], p2 = polygon[x], p3 = polygon[x2], p4 = polygon[x3];

        ans = max({ans, dist2(p, p2), dist2(p, p3), dist2(p, p4)});
    }

    cout << setprecision(12) << fixed << ans << endl;
}