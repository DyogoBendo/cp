#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int area2(pair<int, int> v, pair<int, int> u){
    int dx = v.first - u.first;
    int dy = v.second- u.second;

    return dx*dx + dy*dy;
}

struct segment {
	int x1, y1, x2, y2, index;	
	bool operator<(segment const& o) const {
		if (x2 < o.x2) {
			return (long long) (y2 - o.y1) * (long long) (o.x2 - o.x1) <
			       (long long) (o.y2 - o.y1) * (long long) (x2 - o.x1);
		} else {
			return (long long) (o.y2 - y1) * (long long) (x2 - x1) >
			       (long long) (y2 - y1) * (long long) (o.x2 - x1);
		}
	}
};

int main(){
    setIO("hillwalk");

    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> entries;
    vector<segment> segments(n);

    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        entries.push_back({x1, 0, y1, i});
        entries.push_back({x2, 1, y2, i});
        segment s;
        s.x1 = x1, s.x2 = x2, s.y1 = y1, s.y2 = y2, s.index = i;
        segments[i] = s;
    }

    sort(entries.begin(), entries.end());

    set<segment> open;

    int curr_idx = 0, cnt = 1;
    bool done = false;
    for(int i = 0; i < 2*n && !done; i++){        
        auto [x, op, y, idx] = entries[i];        
        if(i == 0){
            curr_idx = idx;
            open.insert(segments[idx]);
            continue;
        }

        if(op == 0){
            open.insert(segments[idx]);
        } else{
            auto it= open.find(segments[idx]);                
            if(idx == curr_idx){
                if(it == open.begin() ){
                    done = true;
                } else{           
                    auto it2 = it;       
                    it2--;                      
                    curr_idx = it2->index;                    
                    cnt++;                                        
                }                                
            } 
            open.erase(it);

        }

    }

    cout << cnt << endl;
}