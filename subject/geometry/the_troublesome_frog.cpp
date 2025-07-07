#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

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


signed main(){
    darvem;

    int r, c, n;
    cin >> r >> c >> n;

    vector<pt> pts(n);
    
    vector<vector<bool>> used(r + 1, vector<bool>(c+1));

    auto inside = [&](pt p){        
        if(p.x <= 0 or p.x > r) return false;
        if(p.y <= 0 or p.y > c) return false;
        return true;
    };

    auto check_pos = [&](pt p){        
        if(!inside(p)) return false;

        return (bool) used[p.x][p.y];
    };

    for (int i = 0; i < n; i++)
    {
        cin >>pts[i];
        used[pts[i].x][pts[i].y] = true;
    }

    sort(pts.begin(), pts.end());

    int ans= 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cnt = 2;
            pt diff = pts[j] - pts[i];
            pt left = pts[i] - diff;

            if(inside(left)) continue;

            pt right = pts[j] + diff;
            while(check_pos(right)){
                right = right + diff;
                cnt++;
            }

            if(!inside(right) && cnt > 2){
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << endl;
}