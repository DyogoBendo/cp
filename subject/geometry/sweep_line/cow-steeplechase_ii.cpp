#include <bits/stdc++.h>
#define ll long long

using namespace std;

// Geometria - inteiro

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

// PONTO & VETOR

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

int quad(pt p) { // quadrante de um ponto
	return (p.x<0)^3*(p.y<0);
}

bool compare_angle(pt p, pt q) { // retorna se ang(p) < ang(q)
	if (quad(p) != quad(q)) return quad(p) < quad(q);
	return ccw(q, pt(0, 0), p);
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

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


void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("cowjump");

    int n;
    cin >> n;

    vector<line> segments(n);
    
    vector<pair<pt, int>> events;

    for (int i = 0; i < n; i++)
    {
        pt p1, p2;
        cin >> p1 >> p2;        

        segments[i] = line(p1, p2);

        events.push_back({p1, i});
        events.push_back({p2, i});
    }    

    sort(events.begin(), events.end());

    auto cmp = [](pair<pt, int> x, pair<pt, int> y){
        pt p = x.first;
        pt q = y.first;
        return p.y < q.y or (p.y == q.y && p.x < q.x);
    };
    set<pair<pt, int>, decltype(cmp)> active_segments(cmp);
    
    vector<int> visited(n);    
    vector<pt> curr_pt(n);

    vector<int> candidates;

    for (int i = 0; i < 2*n; i++)
    {
        auto [p, idx] = events[i];        

        if(visited[idx]){            
            auto it = active_segments.find({curr_pt[idx], idx});            
            if(it != active_segments.begin() && interseg(segments[idx], segments[prev(it)->second])){                
                candidates = {idx, prev(it)->second};
                break;
            }
            if(it != active_segments.end() && next(it) != active_segments.end() && interseg(segments[idx], segments[next(it)->second])){            
                candidates = {idx, next(it)->second};
                break;
            }

            active_segments.erase({curr_pt[idx], idx});

        } else{
            auto it = active_segments.lower_bound({p, idx});            

            if(it != active_segments.begin() && interseg(segments[idx], segments[prev(it)->second])){                
                candidates = {idx, prev(it)->second};
                break;
            }
            if(it != active_segments.end() && next(it) != active_segments.end() && interseg(segments[idx], segments[next(it)->second])){                
                candidates = {idx, next(it)->second};
                break;
            }

            visited[idx] = 1;
            curr_pt[idx] = p;
            active_segments.insert({p, idx});

        }
    }
    
    vector<int> cnt(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j == candidates[i]) continue;   
                    
            cnt[i] += interseg(segments[candidates[i]], segments[j]);
        }        
    }    
    
    int ans;
    if(cnt[0] == cnt[1]) ans = *min_element(candidates.begin(), candidates.end());
    else if(cnt[0] > cnt[1]) ans = candidates[0];
    else ans = candidates[1];
    
    cout << ans+1 << endl;
}