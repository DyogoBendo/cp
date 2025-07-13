#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

typedef long double ld;
const ld DINF = 1e50;
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

const int MAX = (1 << 8);

ld dp[MAX][52][2];
bool tem[MAX][52][2];

signed main(){
    int n, m;

    cin >> n >> m;

    vector<pt>v(n);
    vector<int> terminal(n, false), S;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<line> ms(m);

    for (int i = 0; i < m; i++)
    {
        cin >> ms[i];
    }

    int s;
    cin >> s;

    for (int i = 0; i < s; i++)
    {
        int x;
        cin >> x;

        terminal[--x] = true;
        S.push_back(x);
    }
    
    vector<vector<ld>> matrix(n, vector<ld>(n, DINF));

    auto intersecta_muro = [&](int i, int j){
        pt p = v[i], q = v[j];
        
        line s(p, q);        

        for (auto m : ms)
        {
            if(interseg(m, s)) return true;
        }        
        return false;        
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ld dst = !intersecta_muro(i, j) ? dist(v[i], v[j]) : DINF;
            matrix[i][j] = matrix[j][i] = dst;
        }        
    }

        for (ll k=0;k<n;k++)
        for (ll i=0;i<n;i++)
            for (ll j=0;j<n;j++)
                if (matrix[i][k] + matrix[k][j] <= matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];   

    function<ld(ll, ll, int)> calc = [&](ll mask, ll u, int pfolha){
        if(mask == 0) return (ld) 0;

        if(__builtin_popcount(mask) == 1)
         return matrix[u][S[__builtin_ctz(mask)]];
        
        if(tem[mask][u][pfolha]) return dp[mask][u][pfolha];

        ld best = DINF;

        ll x=(mask - 1) & mask;

        while(x){
            best = min(best, calc(x, u, 1) + calc(x^mask, u, 1));
            x = (x-1) & mask;
        }

        if(pfolha){
            for(int i = 0; i < s; i++) if(mask&(1<<i)){
                best = min(best, matrix[u][S[i]] + calc(mask^(1<<i), S[i], 1));
            }
            for(int i = 0; i < n; i++) if(!terminal[i]){
                best = min(best, matrix[u][i] + calc(mask, i, 0));
            }
        }

        tem[mask][u][pfolha] = true;
        return dp[mask][u][pfolha] = best;
    };
        
    memset(tem,false,sizeof(tem));
    ld resp = calc((1<<s) - 1, S[0], 1);

    if(resp < DINF) printf("%.3Lf\n", resp);
    else printf("impossivel\n");
    
}