#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)

void setIO(string s) {        
    freopen((s + ".out").c_str(), "w", stdout);
}
vector<string> reference;

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

bool is_var(string &s, int i){
    bool is_var = true;
    if(i > 0 && s[i-1] != ' ') is_var = false;
    if(i < s.length() - 1 && s[i+1] != ' ') is_var = false;
    if(!isalpha(s[i])) is_var = false;        

    return is_var;
}

vector<int> get_var_idx(string &s){
    vector<int> v;
    for (int i = 0; i < s.length(); i++)
    {        
        if(is_var(s, i)) v.push_back(i);
    }

    return v;
}

template<typename T> bool matching(T& s, T& t, T& s0, T& t0) {    
    //cout << "s: " <<s << " t: " << t << " s0: " << s0 << " t0; " << t0 << endl;
	vector<int> p = pi(s);
    vector<int> var_idx = get_var_idx(s);
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()){                                     
            return true;
        } 
	}
	return false;
}

int main(){
    // setIO("out");        
    int n;
    cin >> n;
    string reference = "", tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(i > 0) reference += ' ';
        reference += tmp;
    }

    string r2 = reference;

    vector<char> av;
    av.push_back('#');

    for (int i = 0; i < 26; i++)
    {
        av.push_back('a' + i);
    }

    for (int i = 0; i < 26; i++)
    {
        av.push_back('A' + i);
    }


    map<char, int> rc;
    int lst= 0;
    for (int i = 0; i < r2.length(); i++)
    {
        if(is_var(r2, i)){
            char c = r2[i];
            if(rc[c]) r2[i] = av[rc[c]];
            else{
                lst ++;
                rc[c] = lst;                
                r2[i] = av[lst];            
            } 
        } 
    }
    

    int q;
    cin >> q;
    while(q--){
        int sz;
        cin >> sz;

        string code = "";
        for (int i = 0; i < sz; i++)
        {
            string tmp;
            cin >> tmp;
            if(i > 0) code += ' ';
            code += tmp;
        }
        
        string c2 = code;

        map<char, int> cc;
        lst= 0;
        for (int i = 0; i < code.length(); i++)
        {
            if(is_var(code, i)){
                char c = c2[i];
                if(cc[c]) c2[i] = av[cc[c]];
                else{
                    lst ++;
                    cc[c] = lst;                
                    c2[i] = av[lst];    
                } 
            } 
        }        
        
        bool possible = matching(c2, r2, code, reference);
        
        cout << (possible ? "yes" : "no") << endl;
    }
    
}