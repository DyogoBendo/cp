#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define ld long double
#define INF = 1e18;
const ld DINF = 1e18;


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

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return (a ^ b) == 0 and (a * b) <= 0;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

int inpol(vector<pt>& v, pt p) { // O(n)
	int qt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (p == v[i]) return 2;
		int j = (i+1)%v.size();
		if (p.y == v[i].y and p.y == v[j].y) {
			if ((v[i]-p)*(v[j]-p) <= 0) return 2;
			continue;
		}
		bool baixo = v[i].y < p.y;
		if (baixo == (v[j].y < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (!t) return 2;
		if (baixo == (t > 0)) qt += baixo ? 1 : -1;
	}
	return qt != 0;
}


signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pt> pts(n+1), polygon;
    for(int i = 0; i <= n; i++){
        cin >> pts[i];
        pts[i] = pts[i] * 2;
        if(i<n) polygon.push_back(pts[i]);
    }    

    vector<vector<pair<int, ld>>> g(n+1);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            bool intersects_other_segments = false;
            line l1(pts[i], pts[j]);
            for(int k = 0; k < n && !intersects_other_segments; k++){
                if(min(k, (k+1)%n) == i && max(k, (k+1)%n) == j) continue;
                if(k == i or k == j or (k+1)%n == i or (k+1)%n == j) continue;
                line l2(polygon[k], polygon[(k+1)%n]);

                intersects_other_segments = max(intersects_other_segments, interseg(l1, l2));
            }

            pt m((pts[i].x + pts[j].x) / 2, (pts[i].y + pts[j].y) / 2) ;
            if(!intersects_other_segments && inpol(polygon, m)){
				ld d = sqrt(dist2(pts[i], pts[j]));
                g[i].push_back({j, d});
                g[j].push_back({i, d});
            } 
        }
    }

    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> pq;

    pq.push({0, 0});
    vector<ld> dst(n+1, DINF);
    vector<int> visited(n+1);
    dst[0] = 0;

    

    while(!pq.empty()){
        auto [d, idx] = pq.top(); pq.pop();
        if(visited[idx]) continue;
        visited[idx] = 1;

        for (auto [i, w] : g[idx])
        {
            if(d + w < dst[i] ){
                dst[i] = d+ w; 
                pq.push({d + w, i});
            } 
        }
    }

    cout << fixed << setprecision(12) << dst[n] << endl;
}