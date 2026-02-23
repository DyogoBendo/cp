#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

int to_hex_value(char c){
    if(c >= '0' and c <= '9') return c - '0';
    else return c - 'A' + 10;
}

string hex_to_string(char b){
    int h = to_hex_value(b);
    string s;
    for(int i = 0; i < 4; i++){
        char c = '0' + (h%2);
        s += c;
        h /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

char string_to_byte(string s){
    reverse(s.begin(), s.end());
    int curr = 0;
    int p = 1;    
    for(int i = 0; i < sz(s); i++){
        if (s[i] == '1'){
            curr += p;
        }
        p *= 2;
    }   

    if(curr < 10) return '0' + curr;
    else return 'A' + (curr % 10);    
}

string string_invert(string s){
    int f = s[0] - '0';
    string inv = "";        
    for(int i = 1; i < sz(s); i++){        
        int x = (s[i] - '0');       
        x ^= f;                 
        inv += ('0' + x);
    }       

    return inv;
}



void encrypt(string s){    
    string base_ans = "";
    for(int i = 0; i < sz(s); i+=2){        
        base_ans+= hex_to_string(s[i]);
        base_ans+= hex_to_string(s[i+1]);
    }


    string b2;
    for(int i = 0; i < sz(base_ans) + 8; i++) b2 += '1';

    for(int i = 0; i < sz(base_ans) + 8; i+= 8) b2[i] = '0';

    int j = 0;
    for(int i = 0; i < sz(base_ans); i++){
        if(b2[j] == '0') j++;
        b2[j] = base_ans[i];
        j++;
    }

    string ans;
    for(int i = 0; i < sz(b2); i+= 4){
        ans += string_to_byte(b2.substr(i, 4));
    }
    cout << ans << endl;
}

void decrypt(string s){
    string base_ans = "";
    for(int i = 0; i < sz(s); i+= 2){
        base_ans+= hex_to_string(s[i]);
        base_ans+= hex_to_string(s[i+1]);
    }    

    string removed_flags;

    for(int i = 0; i < sz(base_ans); i+= 8){
        removed_flags += string_invert(base_ans.substr(i, 8));
    }    

    string ans;
    for(int i = 0; i < sz(removed_flags); i+= 4){
        ans += string_to_byte(removed_flags.substr(i, 4));
    }
    cout << ans << endl;
}

void solve(){
    string s, t;
    int n;
    cin >> n >> t;        

    for (int i=0; i<n; i++){
        cin >> s;

        if(t == "encrypt") encrypt(s);
        else decrypt(s);
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}