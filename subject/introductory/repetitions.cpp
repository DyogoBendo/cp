#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;

    cin >> s;

    int current = 1;
    char c = s[0];

    int m = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if(s[i] == c){
            current ++;
        } else{
            c = s[i];
            current = 1;
        }
        if(current > m) m = current;

    }
    
    cout << m << endl;
}