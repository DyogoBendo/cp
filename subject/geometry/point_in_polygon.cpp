#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long


// se pegarmos o ponto como central e calcularmos a área dos triângulos a partir dele, a área precisa ser igual a área do polígono para ele estar contido, senão ele está fora
// como verificar se ele está nos limites do polígono? a área precisa ser a mesma do polígono e precisa ser colinear? 


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


ll dst2(pt p1, pt p2){
    ll dx = p1.x - p2.x;
    ll dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

bool is_colinear(pt p1, pt p2, pt p3){
    return ((p2 - p1) ^ (p3 - p1)) == 0;
}

bool is_in_segment(pt p, pt s1, pt s2){
    if(!is_colinear(p, s1, s2)) return false;

    ll segd = dst2(s1, s2);

    ll d1 = dst2(s1, p), d2 = dst2(d2, p);

    return d1 <= segd && d2 <= segd;
}

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<pt> polygon(n);
    for(auto &p : polygon) cin >> p;

    ll parea = 0;

    for (int i = 1; i <= n; i++)
    {
        parea += polygon[i - 1] ^ polygon[i%n];
    }

    parea = abs(parea);

    auto solve = [&](){
        pt p;
        cin >> p;
        ll area = 0;
            
        for (int i = 1; i <= n; i++)
        {
            pt prev = polygon[i - 1], curr = polygon[i%n];
            if(is_in_segment(p, prev, curr)){
                cout << "BOUNDARY" << endl;
                return;
            }                        
        }
        
                
    };

    while(m--){
        solve();
    }

}