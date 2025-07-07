#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double
const ld eps = 1e-9;
const ld DINF = 1e18;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c, y*c); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}	
};

bool ccw(pt p1, pt p2, pt p3){
    pt v1 = p2 - p1;
    pt v2 = p3 - p2;

    return (v2 ^ v1) > 0;
}

ll dst2(pt p1, pt p2){
    ll dx = p1.x - p2.x;
    ll dy = p1.y - p2.y;
    return  dx*dx+ dy*dy;
}

void print_p(pt p){
    cout << "(" << p.x << ", "  << p.y << ")" << endl;
}
ld dist(pt p, pt q){
    ld ans = hypot(p.y - q.y, p.x - q.x); 
    return ans;
}

ld sarea(pt p, pt q, pt r){
    return  ( (ld) ( (q - p) ^ (r - p))) / 2.0;
}

ld dist_pt_line(pt p, line r){
    ld ans = 2 * abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
    return ans;;
}

ld dist_pt_seg(pt p, line r){
    if ((r.q - r.p)*(p - r.p) < 0) return dist(r.p, p);
	if ((r.p - r.q)*(p - r.q) < 0) return dist(r.q, p);
    return dist_pt_line(p, r);
}

ld dist_seg_seg(line s, line r){
    if(s.q == s.p && r.q == r.p) return dist(s.q, r.q);
    if(s.q == s.p) return dist_pt_line(s.q, r);
    if(r.q == r.p) return dist_pt_line(r.q, s);
    return min({dist_pt_seg(s.p, r), dist_pt_seg(s.q, r), dist_pt_seg(r.p, s), dist_pt_seg(r.q, s)});
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return eq((a ^ b), 0) and (a * b) < eps;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

ld distseg(line a, line b) { // distancia entre seg
	if (interseg(a, b)) return 0;

    if(a.p == a.q && b.p == b.q) return dist(a.p, b.p);
    if(a.p == a.q) return dist_pt_seg(a.p, b);
    if(b.p == b.q) return dist_pt_seg(b.p, a);

	ld ret = DINF;
	ret = min(ret, dist_pt_seg(a.p, b));
	ret = min(ret, dist_pt_seg(a.q, b));
	ret = min(ret, dist_pt_seg(b.p, a));
	ret = min(ret, dist_pt_seg(b.q, a));

	return ret;
}

void solve(){
    vector<pt> v(4);

    for (int i = 0; i < 4; i++)
    {
        cin >> v[i];
    }

    line s1(v[0], v[1]), s2(v[2], v[3]);

    cout << distseg(s1, s2) << endl;
}


signed main(){
    cout << setprecision(2) << fixed;
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}