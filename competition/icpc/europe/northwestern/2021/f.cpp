#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
            tree_order_statistics_node_update> ost;

#define sq(x) ((x)*(ll)(x))

struct pt { // ponto
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ll c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
    friend ostream& operator << (ostream& out, pt& p) {
		return out << p.x << " " << p.y;
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

ll quad(pt p) { // quadrante de um ponto
	if (p.x >= 0 && p.y >= 0) return 0;
    if (p.x <  0 && p.y >= 0) return 1;
    if (p.x <  0 && p.y <  0) return 2;
    return 3;
}

bool compare_angle(pt p, pt q) { // retorna se ang(p) < ang(q)
	if (quad(p) != quad(q)) return quad(p) < quad(q);
	return ccw(q, pt(0, 0), p);
}

void sort_by_pt(pt reference, vector<pt> &pts, bool d){
    sort(pts.begin(), pts.end(), [&](pt p1, pt p2){
        if(col(p1, p2, reference)){
            if(d) return dist2(p1, reference) < dist2(p2, reference);
            else return dist2(p1, reference) > dist2(p2, reference);
        } 
        return compare_angle(p1 - reference, p2 - reference);
    });
}

map<pt, int> get_id(vector<pt> &pts){
    map<pt, int> mp; int cnt=1;
    for (auto p : pts)
    {
        assert(mp.count(p) == 0);
        mp[p] = cnt ++;
    }
    return mp;    
}

ll count_inversions(vector<int> &v){
    ost s;

    ll inv = 0;
    int n = (ll) v.size();

    for (ll i = n - 1; i >= 0; i--)
    {
        ll add = (ll) s.order_of_key(v[i]);
        inv += add;
        s.insert(v[i]);
    }

    return inv;    
}

ll solve1(pt st, pt en, vector<pt> &pts, int curr){    
    sort_by_pt(st, pts, 1 ^ curr);
    map<pt, int> id_map = get_id(pts);    

    sort_by_pt(en, pts, 0 ^ curr);

    vector<int> v;
    for (auto p : pts)
    {        
        v.push_back(id_map[p]);        
    }    

    return count_inversions(v);    
}

ll solve2(vector<pt> &pts){    
    ll n = (ll) pts.size();

    return 1LL * (n-1LL) * (n) / 2LL;
}

signed main(){
    darvem;

    pt st, en;
    cin >> st >> en;

    ll n;
    cin >> n;

    vector<pt> above, below, left, right;

    for (ll i = 0; i < n; i++)
    {
        pt p;
        cin >> p;

        if(col(st, p, en)){
            if(p < st) left.push_back(p);
            else right.push_back(p);
        } else{
            if(ccw(st, en, p)) above.push_back(p);
            else below.push_back(p);
        }
    }    

    ll ans = solve1(st, en, below, 1) + solve1(st, en, above, 0) + solve2(left) + solve2(right);

    cout << ans << endl;
}