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

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}


int n;
void solve(){
    vector<pt> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());

    ld d = DINF;
    pt a1, a2;

    auto cmp = [](pt a, pt b){return a.y < b.y or (a.y == b.y && a.x < b.x);};
    set<pt, decltype(cmp)> active(cmp);
    queue<pt> q;
    for (int i = 0; i < n; i++)
    {
        while(!q.empty()){
            if(q.front().x + d < v[i].x){
                active.erase(q.front());
                q.pop();
            } 
            else break;
        }                


        auto st = active.lower_bound({-DINF, v[i].y - d});

        while(st != active.end() && fabs(st->y - v[i].y) <= d){            
            ld calc = dist(*st, v[i]);
            if(calc < d){
                d = calc;
                a1 = *st;
                a2 = v[i];
            }
            st++;
        }
        q.push(v[i]);
        active.insert(v[i]);
        
    }

    cout << setprecision(2) << fixed << a1.x << " " << a1.y << " " << a2.x << " " << a2.y << endl;
}


signed main(){
    darvem;
    cin >> n;

    while(n){
        solve();
        cin >> n;
    }
}