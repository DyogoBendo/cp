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


int calc_points_seg(pt a, pt b){
    int dx = abs(a.x - b.x);
    int dy = abs(a.y - b.y);

    return __gcd(dx, dy);
}

ll pick(ll a, ll b){
    return (a - b)/2 + 1;
}

signed main(){
    //darvem;

    int n;
    cin >> n;

    vector<pt> poly(n);

    for (int i = 0; i < n; i++)
    {
        cin >> poly[i];
    }

    ll border_points= 0;
    ll area = 0;

    for (int i = 0; i < n; i++)
    {
        pt curr = poly[i], prox = poly[(i+1)%n];
        
        border_points += calc_points_seg(curr, prox);

        area += curr ^ prox;
    }   
    
    area = abs(area);

    ll inside = pick(area, border_points);
    
    cout << inside << " " << border_points << endl;
}