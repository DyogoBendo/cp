#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

// Geometria

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

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

// PONTO & VETOR

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ld norm(pt v) { // norma do vetor
	return dist(pt(0, 0), v);
}

ld angle(pt v) { // angulo do vetor com o eixo x
	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

bool isvert(line r) { // se r eh vertical
	return eq(r.p.x, r.q.x);
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return eq((a ^ b), 0) and (a * b) < eps;
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt proj(pt p, line r) { // projecao do ponto p na reta r
	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	pt proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

pt inter(line r, line s) { // r inter s
	if (eq((r.p - r.q) ^ (s.p - s.q), 0)) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

ld disttoline(pt p, line r) { // distancia do ponto a reta
	return 2 * abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
}

ld disttoseg(pt p, line r) { // distancia do ponto ao seg
	if ((r.q - r.p)*(p - r.p) < 0) return dist(r.p, p);
	if ((r.p - r.q)*(p - r.q) < 0) return dist(r.q, p);
	return disttoline(p, r);
}

ld distseg(line a, line b) { // distancia entre seg
	if (interseg(a, b)) return 0;

	ld ret = DINF;
	ret = min(ret, disttoseg(a.p, b));
	ret = min(ret, disttoseg(a.q, b));
	ret = min(ret, disttoseg(b.p, a));
	ret = min(ret, disttoseg(b.q, a));

	return ret;
}

bool operator <(const line& a, const line& b) { // comparador pra reta
	// assume que as retas tem p < q
	pt v1 = a.q - a.p, v2 = b.q - b.p;
	if (!eq(angle(v1), angle(v2))) return angle(v1) < angle(v2);
	return ccw(a.p, a.q, b.p); // mesmo angulo
}
bool operator ==(const line& a, const line& b) {
	return !(a < b) and !(b < a);
}

// comparador pro set pra fazer sweep line com segmentos
struct cmp_sweepline {
	bool operator () (const line& a, const line& b) const {
		// assume que os segmentos tem p < q
		if (a.p == b.p) return ccw(a.p, a.q, b.q);
		if (!eq(a.p.x, a.q.x) and (eq(b.p.x, b.q.x) or a.p.x+eps < b.p.x))
			return ccw(a.p, a.q, b.p);
		return ccw(a.p, b.q, b.p);
	}
};

// comparador pro set pra fazer sweep angle com segmentos
pt dir;
struct cmp_sweepangle {
	bool operator () (const line& a, const line& b) const {
		return get_t(dir, a) + eps < get_t(dir, b);
	}
};

pt get_pt(ld tan, pt p){
	ld y = tan + p.y;
	dbg(p.x+1, y);
	return pt(p.x + 1, y);
}

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pt> pts(n);

    for(int i = 0; i < n; i++) cin >> pts[i];

    vector<ld> angles(n);

    for(int i = 0; i < n; i++){
        int prev = (i - 1+ n) % n;
        int prox = (i + 1) % n;

        ld ang_prev = angle(pts[prev] - pts[i]);
        ld ang_prox = angle(pts[prox] - pts[i]);
        
        angles[i] = abs(ang_prev - ang_prox);
        dbg(i, prev, prox, pts[i].x, pts[i].y, ang_prev, ang_prox, angles[i]);
    }

    for(int i = 0; i < n; i++) dbg(i, angles[i]);

	ld ideal_angle = pi/4;
	ld ninety = pi/2;

	ld ans = 0;

	dbg(tanl(ideal_angle));
	for(int i = 0; i < n; i++){
		int prev = (i - 1+ n) % n;
        int prox = (i + 1) % n;
		ld ang_prev = pi - angles[prev];
        ld ang_prox = pi - angles[prox];
		
		if(ang_prev <= eps or ang_prox <= eps) continue;
		
		dbg(i, ang_prev, ang_prox);
		if(ang_prev + ang_prox > ninety){
			if(ang_prev >= ideal_angle and ang_prox >= ideal_angle){
				ang_prev = ideal_angle;
				ang_prox = ideal_angle;
			} else if(ang_prev < ideal_angle){
				ang_prox = ninety - ang_prev;
			} else if(ang_prox < ideal_angle){
				ang_prev = ninety - ang_prox;
			}
		}		

		dbg(i, ang_prev, ang_prox);
		ld tan_prev, tan_prox;		
		
		if(pts[prev].y > pts[prox].y){			
			tan_prox = tanl(angle(pts[prev] - pts[prox]) - ang_prox);
			tan_prev = tanl(angle(pts[prox] - pts[prev]) + ang_prev);
		} else{						
			tan_prev = tanl(angle(pts[prox] - pts[prev]) - ang_prev);
			tan_prox = tanl(angle(pts[prev] - pts[prox]) + ang_prox);
		}

		dbg(tan_prox, tan_prev);


		line line_prev = line(get_pt(tan_prev, pts[prev]), pts[prev]);
		line line_prox = line(get_pt(tan_prox, pts[prox]), pts[prox]);

		pt p = inter(line_prev, line_prox);

		ld d_prev = dist(pts[prev], pts[i]) + dist(pts[prox], pts[i]);
		ld d_updated = dist(pts[prev], p) + dist(pts[prox], p);
		dbg(i, d_prev, d_updated, p.x, p.y);

		ld d = d_updated - d_prev;
		ans = max(ans, d);
	}

	cout << fixed << setprecision(12) << ans << endl;
}