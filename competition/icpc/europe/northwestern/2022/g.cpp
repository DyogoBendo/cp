#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MAX = 25;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int go_right(){
    cout << "? right" << endl;
    cout.flush();
    int l;
    cin >> l;
    return l;
}

int update(){
    cout << "? flip" << endl;
    cout.flush();
    int f;
    cin >> f;
    return f;
}


void print_ans(int x){
    cout << "! " << x << endl;
    cout.flush();
}

char get_random_char(){
    return '0' + (uniform(0, 1));
}   

string get_random(){
    string s;

    for(int i = 0; i < MAX; i++){
        s += get_random_char();
    }

    return s;
}

void update_string(string &s, int x){
    if(s.size() == MAX){
        for(int i = 0; i < s.size() - 1; i++){
            s[i] = s[i+1];
        }
        s[s.size() - 1] = '0' + x;
    } else{
        s += '0' + x;
    }
}

signed main(){
    string pattern = get_random();
    string curr = "";

    int i = 0, c, walk = 0;
    cin >> c;

    while(curr != pattern){
        if(c + '0' != pattern[curr.size()] && curr.size() < MAX) update();
        update_string(curr, c);
        c = go_right();
        walk++;
    }


    print_ans(walk - MAX);
}