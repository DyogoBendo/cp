#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

struct pt { // ponto
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
        if (x != p.x) return x < p.x;
		if (y != p.y) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
        return x == p.x && y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ll c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ll c) const { return pt(x/c  , y/c  ); }
	ll operator * (const pt p) const { return x*p.x + y*p.y; }
	ll operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
	}
};
pt origin;

ll cross(pt a, pt b){
    return (b-origin) ^ (a-origin);
}

int half(pt p){
    if (p.x != origin.x) return (p.x < origin.x) - (p.x > origin.x);
	return (p.y < origin.y) - (p.y > origin.y);
}

struct Event{
    int type, id;
    pt loc;
    Event(int t, int i, pt p) : type(t), id(i), loc(p){}
};

bool operator <(Event a, Event b){
    int ah = half(a.loc), bh = half(b.loc);

    if(ah == bh){
        ll c = cross(a.loc, b.loc);
        if(c == 0) return a.type > b.type;
        return c > 0;
    }
    return ah < bh;
}

Event get_next_post(Event curr, int n){
    if (curr.loc.x == n) {
		if (curr.loc.y) return {0, 0, {n, curr.loc.y - 1}};
		return {0, 0, {n - 1, 0}};
	} else if (!curr.loc.x) {
		if (curr.loc.y != n) return {0, 0, {0, curr.loc.y + 1}};
		return {0, 0, {1, n}};
	} else if (curr.loc.y == n) {
		if (curr.loc.x != n) return {0, 0, {curr.loc.x + 1, n}};
		return {0, 0, {n, n - 1}};
	} else {
		if (curr.loc.x) return {0, 0, {curr.loc.x - 1, 0}};
		return {0, 0, {0, 1}};
	}
}

vector<Event> events;
bool before[44444];

signed main(){
    darvem;

    int n, r;
    cin >> n >> r  >> origin; 


    for (int i = 0; i < r; i++)
    {
        int s;
        cin >> s;

        vector<pt> vertices(s);
        for(int i =0; i < s; i++) cin >> vertices[i];

        sort(vertices.begin(), vertices.end(), [](pt a, pt b){
            return cross(a, b) > 0;
        });        

        events.push_back(Event(1, i, vertices[0]));
        events.push_back(Event(-1, i, vertices.back()));
        
    }

    sort(events.begin(), events.end());

    int active = 0;    

    for (Event i : events) {
		if (i.type == 1) before[i.id] = true;
		if (i.type == -1 && !before[i.id]) active++;
	}  
    
	int ans = 0, ptr = 0;
	Event curr_post = {0, 0, {origin.x, n}};
	for (Event i : events) {        
		while (ptr != 4 * n && curr_post < i) {
			// If there are no rocks that our current ray intersects...
			if (!active) ans++;
			ptr++;
			curr_post = get_next_post(curr_post, n);
		}

		if (i.type == 1) active++;
		else active--;
	}
	if (!active) ans += 4 * n - ptr;
    
    cout << ans << endl;
}