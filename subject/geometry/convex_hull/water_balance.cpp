#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double
#define int long long

#define sq(x) ((x)*(ll)(x))

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

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

vector<pt> lower_convex_hull(vector<pt> v) { // convex hull - O(n log(n))
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (v.size() <= 1) return v;
	vector<pt> l;
	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i]))
			l.pop_back();
		l.push_back(v[i]);
	}	
	return l;
}

ld slope(pt a, pt b){    
    return ( (ld) (b.y - a.y))/(b.x - a.x);
}

signed main(){
    darvem;

    int n;
    cin >> n;
    vector<int> v(n), psum(n+1);
    vector<pt> pts(n+1);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + v[i-1];
    for(int i = 0; i <= n; i++) pts[i] = pt(i, psum[i]);

    vector<pt> hull = lower_convex_hull(pts);

    for(int i = 1; i < hull.size(); i++){
        pt prev=  hull[i-1], curr = hull[i];        
        for(int j = prev.x; j < curr.x; j++){
            cout << setprecision(12) << fixed << slope(prev, curr) << endl;
        }
    }    

}