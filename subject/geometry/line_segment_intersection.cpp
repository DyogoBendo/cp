#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

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

ll ccw(pt p1, pt p2, pt p3){
    pt v1 = p2 - p1;
    pt v2 = p3 - p2;

    return v1 ^ v2;
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
        int st1 = min(v[0].x, v[1].x);
        int en1 = max(v[0].x, v[1].x);
        int st2 = min(v[2].x, v[3].x);
        int en2 = max(v[2].x, v[3].x);
        if((st1 <= v[2].x && v[2].x <= en1) or (st1 <= v[3].x && v[3].x <= en1) or (st2 <= v[0].x && v[0].x <= en2) or (st2 <= v[1].x && v[1].x <= en2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else{
        if(((a1 <= 0 && a2 >= 0) || (a1 >= 0 && a2 <= 0)) && ((a3 <= 0 && a4 >=0) || (a3 >=0 && a4 <= 0))) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}