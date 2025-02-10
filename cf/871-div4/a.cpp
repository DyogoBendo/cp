#include <bits/stdc++.h>

using namespace std;

const string CODEFORCES ="codeforces";

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int qtd = 0;
        cin >> s;
        for (int i = 0; i < 10; i++)
        {
            if(s[i]!= CODEFORCES[i]){
                qtd ++;
            }
        }
        
        cout << qtd << endl;
    }
}