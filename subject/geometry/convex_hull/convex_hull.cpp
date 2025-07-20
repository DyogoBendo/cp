#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

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

    while(n){
        vector<pt> pts(n);
        for(int i = 0; i < n; i++){
            cin >> pts[i];
        }
        
        auto ans = convex_hull(pts);
        cout << ans.size() << endl;
        for(auto a : ans) cout << a.x << ' ' << a.y << endl;

        cin >> n;
    }
}