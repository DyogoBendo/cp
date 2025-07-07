#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double

#define sq(x) ((x)*(ll)(x))

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
	ld operator * (const pt p) const { return x*(ld)p.x + y*(ld)p.y; }
	ld operator ^ (const pt p) const { return x*(ld)p.y - y*(ld)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}	
};

ll ccw(pt p1, pt p2, pt p3){
    pt v1 = p2 - p1;
    pt v2 = p3 - p2;

    return v1 ^ v2;
}

ll dst2(pt p1, pt p2){
    ll dx = p1.x - p2.x;
    ll dy = p1.y - p2.y;
    return  dx*dx+ dy*dy;
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) /((r.p-r.q)^v);
}

void calc_x(pt pa1, pt pa2, pt pb1, pt pb2){
    line r(pa1, pa2), s(pb1, pb2);    
    r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;    
	pt ans = r.q * get_t(r.q, s) + r.p;

    cout << ans.x << " " << ans.y << endl;
}

void solve(){
    vector<pt> v(4);

    for (int i = 0; i < 4; i++)
    {
        cin >> v[i];
    }
    
    ll a1 = ccw(v[0], v[2], v[1]);
    ll a2 = ccw(v[0], v[3], v[1]);
    ll a3 = ccw(v[2], v[0], v[3]);
    ll a4 = ccw(v[2], v[1], v[3]);

    if(a1 == a2 && a1 == a3 && a3 == a4 && a1 == 0){ // pertencem a mesma reta

        if(v[1] < v[0]) swap(v[0], v[1]);
        if(v[3] < v[2]) swap(v[2], v[3]);

        ll d1 = dst2(v[0], v[1]), d2 = dst2(v[0] , v[2]), d3 = dst2(v[2] , v[3]);  
        
        if(v[0] < v[2]){
            if( d1>=d2 ){
                pt l = max(v[0], v[2]);
                pt r = min(v[1], v[3]);
                cout << l.x << " " << l.y;
                if(!(l == r)) cout << " " << r.x << " " << r.y;
                cout << endl;
            } 
            else cout << "none" << endl;
        } else{
            if(d3>= d2){
                pt l = max(v[0], v[2]);
                pt r = min(v[1], v[3]);
                cout << l.x << " " << l.y;
                if(!(l == r)) cout << " " << r.x << " " << r.y;
                cout << endl;
            }
            else cout << "none" << endl;
        }
        
        
    } else{                     
        if(((a1 <= 0 && a2 >= 0) || (a1 >= 0 && a2 <= 0)) && ((a3 <= 0 && a4 >=0) || (a3 >=0 && a4 <= 0))) calc_x(v[0], v[1], v[2], v[3]);
        else cout << "none" << endl;
    }
    
}


signed main(){    
    darvem;
    int t = 1;
    cin >> t;

    cout << setprecision(2) << fixed;
    while(t--) solve();
}