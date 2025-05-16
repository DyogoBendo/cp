#include <bits/stdc++.h>

using namespace std;

int soma(int a, int b){
    return a + b;
}
int main(){
    int n;


    string s1, s2;
    s1 = "banana";
    s2 = "macas";
    s1.push_back('-');
    s2.pop_back();
    cout << "sz: " << s1.size() << " - " << s1.length() << endl;
    cout << s1 + s2 << endl;

    for (char c : s1) // for each
    {
        cout << "caracter: " << c << endl;
    }
    
    int a = 10, b = 20;

    cout << min({a, b, 15, 29, 39, 41, 7}) << endl;
}