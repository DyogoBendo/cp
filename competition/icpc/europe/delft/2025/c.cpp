#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) a.size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

bool can = true;

void check_var(vector<string> &digit_letters, vector<string> &zeros, int qtd_var, vector<string> &var){
    int tot= sz(digit_letters) + sz(zeros);
    if(tot < qtd_var){
        can = false;
        return;
    }

    if(sz(digit_letters) == 0 and qtd_var != sz(zeros)){
        can = false;
        return;
    }

    sort(rall(digit_letters));

    vector<string> variables;
    for(auto s : digit_letters) variables.push_back(s);
    for(auto s: zeros) variables.push_back(s);
    int diff = tot - qtd_var;

    string curr = "";
    for(int i = 0; i <= diff; i++){
        curr += variables[i];
    }
    
    var.push_back(curr);
    for(int i = diff + 1; i < sz(variables); i++) var.push_back(variables[i]);
}

void solution(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<string> digits_letters, zeros; 
    int ap = 0, fp = 0; // parentes    
    int mul = 0, sum = 0; // * e +

    for(int i = 0; i < n; i++){
        string tmp = "";
        tmp += s[i];
        if(s[i] > '0' and s[i] <= '9') digits_letters.push_back(tmp);
        else if(s[i] >= 'a' and s[i] <= 'z') digits_letters.push_back(tmp);
        else if(s[i] == '0') zeros.push_back("0");
        else if(s[i] == '(') ap++;
        else if(s[i] == ')') fp++;        
        else if(s[i] == '*') mul++;
        else if(s[i] == '+') sum++;
    }

    int needed_var = mul + sum + 1;
    dbg(ap, fp, mul, sum, needed_var);
    vector<string> var;
    check_var(digits_letters, zeros, needed_var, var);
    if(!can){
        dbg(1);
        cout <<"impossible" << endl;
        return;
    }
    
    if(ap != fp){
        dbg(2);
        cout <<"impossible" << endl;
        return; 
    }
    
    int num_par = ap;
    
    if(num_par == 1){
        if(sum == 0 or mul == 0){
            dbg(3);
            cout <<"impossible" << endl;
            return; 
        }
    } else if(num_par > 1){
        dbg(sum, num_par, mul, num_par-1);
        if(sum < num_par or 2*mul < num_par){
            dbg(4);
            cout <<"impossible" << endl;
            return; 
        }
    }

    cout << "possible" << endl;

    // agora preciso distribuir as variáveis, () + *, para que use todos e não tenham nenhum operação redundante    
    // ((a + b) * (a + c) + d) * e
    while(num_par){
        string a = var.back(); var.pop_back();
        string b = var.back(); var.pop_back();
        string c = "(" + a + "+"+ b + ")";        
        sum--;
        mul--;
        string tmp = c + "*";
        dbg(a, b, c);
        
        if(num_par == 1){        
            dbg(var.back());
            tmp += var.back();
            var.pop_back();            
        } else{
            num_par--;
            sum--;
            string x = var.back(); var.pop_back();
            dbg(x);
            string y = var.back(); var.pop_back();
            dbg(y);
            string z = "(" + x + "+" + y + ")";
            dbg(z);
            
            tmp += z;
        }
        num_par--;
        dbg(tmp);
        var.push_back(tmp);            
    }

    cout << var.back(); var.pop_back();

    while(mul){
        cout << "*" << var.back();
        mul--;        
        var.pop_back();        
    }

    while(sum){
        sum--;
        cout << "+" << var.back();
        var.pop_back();        
    }
    cout << endl;
}

signed main(){
    fastio;
    int cases = 1;

    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    
}