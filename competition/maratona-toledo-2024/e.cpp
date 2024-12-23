#include <bits/stdc++.h>

using namespace std;

vector<int> z;

void calculate_z(string s){       
    int l = 0, r = 0;

    int n = s.size();
    for (int i = 0; i <= n; i++)
    {
        z[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {           
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    
}



int main(){
    string s, p, r;
    cin >> s >> p;        

    vector<int> ans(s.size(), 0);

    z.resize(p.size() + s.size() + 2);
    calculate_z(p + "#" + s);

    for (int i = 0; i < s.size(); i++)
    {
        int k = i + p.size() + 1;        
        int a = ((int) p.size()) == z[k];
        ans[i] = max(ans[i], a);
    }
    
    reverse(p.begin(), p.end());
    calculate_z(p + "#" + s);
    for (int i = 0; i < s.size() ; i++)
    {
        int k = i + p.size() + 1;               
        int a = ((int) p.size()) == z[k];
        ans[i] = max(ans[i], a);
    }    
    

    int qtd = 0;

    for (int i = 0; i < s.size(); i++)
    {        
        qtd += ans[i];
    }    

    cout << qtd << endl;
    
}