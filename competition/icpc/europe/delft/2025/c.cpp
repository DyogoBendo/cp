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
    int ex = 0; // exclamação
    int mul = 0, sum = 0; // * e +

    for(int i = 0; i < n; i++){
        string tmp = "";
        tmp += s[i];
        if(s[i] > '0' and s[i] <= '9') digits_letters.push_back(tmp);
        else if(s[i] >= 'a' and s[i] <= 'z') digits_letters.push_back(tmp);
        else if(s[i] == '0') zeros.push_back("0");
        else if(s[i] == '(') ap++;
        else if(s[i] == ')') fp++;
        else if(s[i] == '!') ex ++;
        else if(s[i] == '*') mul++;
        else if(s[i] == '+') sum++;
    }

    int needed_var = mul + sum + 1;
    vector<string> var;
    check_var(digits_letters, zeros, needed_var, var);
    if(!can){
        cout <<"impossible" << endl;
        return;
    }

    if(ap != fp){
        cout <<"impossible" << endl;
        return; 
    }

    int num_par = ap;

    if(num_par == 1){
        if(sum == 0 or mul == 0){
            cout <<"impossible" << endl;
            return; 
        }
    } else if(num_par > 1){
        if(sum < num_par or mul < num_par - 1){
            cout <<"impossible" << endl;
            return; 
        }
    }

    // SOLUÇÃO PARA O !
    if(ex > 2){
        cout <<"impossible" << endl;
        return; 
    }

    if(ex > 0 and num_par == 0){
        cout << "impossible" << endl;
        return;
    }

    if(ex == 2 and num_par == 1){
        cout << "impossible" << endl;
        return;
    }

    cout << "possible" << endl;
    
    vector<string> comp;
    for(int i = 0; i < num_par; i++){
        string tmp = "(";

        tmp += var.back();
        var.pop_back();

        tmp += "+";
        sum--;

        tmp += var.back();
        var.pop_back();

        if(i == num_par - 1 and num_par > 1){
            for(int j = 0; j < sum; j++){
                tmp += "+";
                tmp += var.back();
                var.pop_back();
            }
    
            while(sz(var)){
                tmp += "*";
                tmp += var.back();
                var.pop_back();
            }

        }

        tmp += ")";
        comp.push_back(tmp);
    }

    if(num_par <= 1){
        cout << var.back();
        var.pop_back();

        for(int j = 0; j < sum; j++){
            cout <<  "+";
            cout << var.back();
            var.pop_back();
        }

        
        for(int j = 0; j < mul; j++){
            cout <<  "*";
            if(sz(var)){
                cout << var.back();
                var.pop_back();
            }
        }
    }
    
    if(ex >= 1) cout << "!";
    for(int i = 0; i < sz(comp); i++){
        cout << comp[i];
        if(i < sz(comp) - 1) cout << "*";
    } 
    if(ex == 2) cout << "!";

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