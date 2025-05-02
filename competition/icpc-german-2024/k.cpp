#include <bits/stdc++.h>

using namespace std;

string ht(string &s){
    string result = s;

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char r;
        if(s[i] == 'b') r = 'd';
        if(s[i] == 'p') r = 'q';
        if(s[i] == 'd') r = 'b';
        if(s[i] == 'q') r = 'p';
        result[n - i - 1] = r;
    }
    
    return result;
}

string vt(string &s){
    string result = s;

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char r;
        if(s[i] == 'b') r = 'p';
        if(s[i] == 'p') r = 'b';
        if(s[i] == 'd') r = 'q';
        if(s[i] == 'q') r = 'd';
        result[i] = r;
    }
    
    return result;
}

string rt(string &s){
    string result = s;

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char r;
        if(s[i] == 'b') r = 'q';
        if(s[i] == 'p') r = 'd';
        if(s[i] == 'd') r = 'p';
        if(s[i] == 'q') r = 'b';
        result[n - i - 1] = r;
    }
    
    return result;
}

int main(){
    string s, t;
    cin >> s >> t;

    int h = 0, v = 0, r = 0;

    for (auto c : t)
    {
        if(c == 'h')  h = (h + 1) % 2;
        else if(c == 'v') v = (v + 1) % 2;
        else r = (r + 1) % 2;
    }

    string ans = s;
    if(h) ans = ht(ans);
    if(v) ans = vt(ans);
    if(r) ans = rt(ans);

    cout << ans << endl;
}