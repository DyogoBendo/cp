#include <bits/stdc++.h>

using namespace std;

int main(){
    string p, a;
    cin >> p >> a;

    vector<int> letrasP(26, 0);
    vector<int> letrasA(26, 0);

    for(auto c: p){
        letrasP[c - 'a']++;        
    }
    int asteristico = 0;
    for (auto c: a)
    {
        if(c != '*') letrasA[c - 'a'] ++;
        else asteristico ++;
    }
    

    int possible = 1;
    int diff = 0;
    for (int i = 0; i < 26; i++)
    {
        if(letrasP[i] < letrasA[i]) possible = 0;
        else diff += letrasP[i] - letrasA[i];
    }
    

    if(diff == asteristico && possible){
        cout << "S" << endl;
    } else{
        cout << "N" << endl;
    }
    
}