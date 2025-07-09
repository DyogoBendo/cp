#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b){return abs(a - b) <= eps;}

struct pt{
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_){}

    bool operator == (const pt p) const{
        return eq(x, p.x) and eq(y, p.y);
    }
    pt operator + (const pt p) const {return pt(x + p.x, y + p.y);}
    pt operator - (const pt p) const {return pt(x - p.x, y - p.y);}
    pt operator * (const ld c) const {return pt(c * x, c*y);}
    pt operator / (const ld c) const {return pt(x / c, y /c);}
    ld operator * (const pt p) const {return x*p.x + y*p.y;}
    ld operator ^ (const pt p) const {return x*p.y - y*p.x;}    
    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }
};

struct line{
    pt p, q;
    line(pt p_, pt q_) : p(p_), q(q_){}
};

pt proj(pt p, line r){
    if(r.p == r.q) return r.p;
    r.q = r.q - r.p; p = p - r.p;
    pt proj = r.q * ((p*r.q) / (r.q*r.q));
    return proj + r.p;
}

ld sarea(pt p, pt q, pt r){
    return ((q - p) ^ (r-q)) / 2;
}

ld dist(pt p, pt q){
    return hypot(p.y - q.y, p.x - q.x);
}

ld disttoline(pt p, line r){
    return 2* abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
}

ld disttoseg(pt p, line r){
    if((r.q - r.p) * (p - r.p) < 0) return dist(r.p, p);
    if((r.p - r.q) * (p - r.q) < 0) return dist(r.q, p);
    return disttoline(p, r);
}

void solve(){    
    int n;
    pt s1, s2;
    cin >> s1 >> s2;
    cin >> n;
    line l(s1, s2);
    ld ans = 0;
    for (int i=0; i<n; i++){
        pt p;
        ld r;
        cin >> p >> r;

        ld d = disttoseg(p, l);

        if(d <= r) {
            ans += r - d;
        }
    }
    cout << setprecision(4) << fixed;
    cout << ans << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}