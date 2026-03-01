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

int get_char_value(char c){
    if(c >= '0' and c <= '9') return c - '0';
    return c - 'A' + 10;
}

int get_byte(char a, char b){
    int x = get_char_value(a);
    int y = get_char_value(b);        

    return (x << 4) + y;
}

char val_to_hex(int c){
    if(c >= 0 and c <= 9) return '0' + c;
    else return 'A' + c - 10;
}

pair<char, char> byte_to_hex(int c){
    int b = c & 15;
    int a = c >> 4;

    return make_pair(val_to_hex(a), val_to_hex(b));
}

void encrypt(){
    string s;
    cin >> s;
    
    int flag = 0;
    for(int i = 0; i < sz(s); i+= 2){
        int b = get_byte(s[i], s[i+1]);                
        int curr = i/2;
        int f = b & 1;
        dbg(curr, f);
        flag |= (f << curr);        
    }    

    dbg(flag);

    auto [x, y] = byte_to_hex(flag);

    cout << x << y << s << endl;    
}

void decrypt(){
    string s;
    cin >> s;

    int flag = get_byte(s[0], s[1]);

    dbg(flag);
    
    set<int> fail_position, correct_position;
    for(int i = 2; i < sz(s); i+=2){
        int b = get_byte(s[i], s[i+1]);
        int lsb = b & 1;
        int curr = i/2 - 1;

        int fb = (flag >> curr) & 1;
        int f = fb ^ lsb;

        dbg(curr, lsb, f, fb);

        if(f) fail_position.insert(curr);
        else correct_position.insert(curr);
    }

    dbg(sz(fail_position));

    if(sz(fail_position) > 4) fail_position = correct_position;

    string ans = "";
    for(int i = 2; i < sz(s); i+=2){
         int curr = i/2 - 1;
         if(fail_position.count(curr)){
            int b = get_byte(s[i], s[i+1]);
            b ^= 255;

            auto [x, y] = byte_to_hex(b);
            ans += x;
            ans += y;
         } else{
            ans += s[i];
            ans += s[i+1];
         }
    }
    
    cout << ans << endl;
}

signed main(){
    darvem;

    int n;
    string type;
    cin >> n >> type;

    while(n--){
        if(type == "encrypt") encrypt();
        else decrypt();        
    }
}