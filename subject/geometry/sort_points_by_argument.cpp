#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
typedef long double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ld calc(pt p){   
    ld y = p.y, x = p.x; 
    return atan2l(y, x);
}

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pt> pts(n);

    for (int i = 0; i < n; i++){
        cin >> pts[i];        
    } 

    sort(pts.begin(), pts.end(), [](const pt &p1, const pt &p2){         
        return calc(p1) < calc(p2);
    });

    for (int i = 0; i < n; i++)
    {
        cout << pts[i].x << " " << pts[i].y << endl;
    }
    
}