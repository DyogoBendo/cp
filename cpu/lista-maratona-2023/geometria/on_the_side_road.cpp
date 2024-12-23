#include <bits/stdc++.h>
using namespace std;

typedef complex<int> P;
#define X real()
#define Y imag()

P point[1001];
bool marked[1001];
set< pair<int, int> > coordinates;
multiset< pair<int, int> > reps;
set< vector<int> > retas;
set<int> possibilities;

pair<int, int> toForm(int c, int a){
    int gcd = __gcd(abs(a), abs(c));
    if (gcd == 0) gcd = 1;

    if (a < 0){
        a = -a;
        c = -c;
    }

    return {c/gcd, a/gcd};
}

vector<int> reta(P x, P y){
    if (x == y) return {0, 0, 0};

    int a, b, c;
    a = y.Y - x.Y;
    b = x.X - y.X;
    c = - a*x.X - b*x.Y;

    int gcd = __gcd(__gcd(a, b), c);
    if (gcd == 0) gcd = 1;

    a /= gcd; b /= gcd; c /= gcd;

    if (a < 0){
        a = -a;
        b = -b;
        c = -c;
    }

    vector<int> r = {a, b, c};
    return r; 
}

int main(){
    int n; cin >> n;
    int x, y;
    for (int i=0; i<n; i++){
        cin >> x >> y;
        point[i] = {x, y};
    }
    

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (marked[j]) continue;

            auto temp = reta(point[i], point[j]);
            if (temp[0] == 0) continue;

            auto t = retas.insert(temp);
            if (t.second) {
                coordinates.insert(toForm(-temp[2], temp[0]));
                reps.insert(toForm(-temp[2], temp[0]));
            }
        }
        marked[i] = 1;
        retas.clear();
    }

    possibilities.insert(n);
    for (auto coordinate: coordinates){
        possibilities.insert(n - reps.count(coordinate));
    }

    cout << possibilities.size();
}