#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int MAXM = 600 + 10;
const int MAXX = 1000 + 10;
const int NICEP = 31;

pair<int, int> message_to_line[MAXM];
pair<int, int> number_to_point[MAXX];
map<pair<int, int>, int> point_to_number;

void init(){
    int cnt = 0;
    for(int i = 0; i < NICEP; i++){
        for(int j = 0; j < NICEP; j++){            
            message_to_line[cnt] = {i, j};

            cnt++;
            if(cnt == MAXM ) break;
        }
        if(cnt == MAXM) break;
    }
    cnt = 1;
    for(int i = 0; i < NICEP; i++){
        for(int j = 0; j < NICEP; j++){
            number_to_point[cnt] = {i, j};
            point_to_number[{i, j}] = cnt;

            cnt++;
            if(cnt == MAXX) break;
        }
        if(cnt == MAXX) break;
    }
}

int calc_y(int a, int b, int x){
    return (a*x + b) % NICEP;
}

vector<int> get_points_from_line(int k){
    auto [a, b] = message_to_line[k];

    vector<int> v(30);
    for(int i = 0; i < 30; i++){
        v[i] = point_to_number[{i, calc_y(a, b, i)}];
    }
    return v;
}

void send(){
    int k;
    cin >> k;

    auto v = get_points_from_line(k);
    for(auto x : v) cout << x << " ";
    cout << endl;
}

void receive(){
    int v1, v2;
    cin >> v1 >> v2;

    pair<int, int> p1 = number_to_point[v1];
    pair<int, int> p2 = number_to_point[v2];

    set<int> s;
    for(int i = 1; i < MAXM; i++){
        auto [a, b] = message_to_line[i];

        if(calc_y(a, b, p1.first) == p1.second) s.insert(i);
    }

    for(int i = 1; i < MAXM; i++){
        auto [a, b] = message_to_line[i];

        if(calc_y(a, b, p2.first) == p2.second){
            if(s.count(i)){
                cout << i << endl;
                return;
            }
        }        
    }
}

signed main(){
    darvem;

    init();

    string action;
    cin >> action;

    if(action == "send") send();
    else receive();
}