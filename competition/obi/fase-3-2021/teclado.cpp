#include <bits/stdc++.h>

using namespace std;

string numeros[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

string n;
int check(string p){
    if(p.size() != n.size()) return 0;

    for (int i = 0; i < p.size(); i++)
    {
        int k = n[i] - '0';
        string a = numeros[k];

        if(a.find(p[i]) == -1) return 0;
    }
    
    return 1;

}

int main(){
    int m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        string p;
        cin >> p;

        ans += check(p);
    }
    
    cout << ans << endl;
}