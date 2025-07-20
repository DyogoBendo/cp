#include <bits/stdc++.h>
#define ll long long

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

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



int main(){
    setIO("squares");

    int n, k;
    cin >> n >> k;

    vector<pair<pt, int>> rect;

    for (int i = 0; i < n; i++)
    {
        pt p, l, r;
        cin >> p; 
        l = p, r = p;
        l.x-=k/2;    
        r.x += k/2;  

        rect.push_back({l, 1});
        rect.push_back({r, 0});
    }

    sort(rect.begin(), rect.end(), [](pair<pt, int> p, pair<pt, int> q){
        return p.first.x < q.first.x or (p.first.x == q.first.x and p.second < q.second) or (p.first.x == q.first.x and p.second == q.second and p.first.y < q.first.y);
    });
    
    auto ysort = [](pt p, pt q){
        return p.y < q.y or (p.y == q.y && p.x < q.x);
    };

    set<pt, decltype(ysort)> active_rect(ysort);

    ll area = 0; // squares that intersects

    auto intersects = [&](pt p, pt q){
        if(q.y < p.y) swap(p, q);        
        if(q.y - p.y < k){
            ll pl = p.x, pr = p.x + k, pu = p.y + k/2, pd = p.y - k/2, ql = q.x, qr = q.x + k, qu = q.y + k/2, qd = q.y - k/2;                        
            // cout << "p: " << pl << " " << pd << " - q: " << ql << " " << qd << endl;
            area = (min(pr, qr) - max(pl, ql)) * (min(pu, qu) - max(pd, qd));
            return true;
        }
        return false; 
    };

    bool possible = true, found=  false;
    for(int i = 0; i < 2*n; i++){
        auto [p, op] = rect[i];

        if(op == 0){
            pt l = p;
            l.x -= k;
            active_rect.erase(l);
        } else{
            int cnt = 0;
            auto curr = active_rect.lower_bound(p);

            int tot = 2;
            while(curr != active_rect.begin() && tot--){
                curr = prev(curr);
            }
            for(int j = 0; j < 4; j++){
                if(curr == active_rect.end()) break;

                cnt += intersects(p, *curr);
                curr = next(curr);
            }              

            if(cnt > 1 or cnt == 1 && found) possible = false;
            if(cnt == 1) found = true;
            active_rect.insert(p);            
        }
    }

    if(!possible) cout << -1 << endl;
    else cout << area << endl;

}