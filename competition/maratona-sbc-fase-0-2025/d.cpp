#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    double x = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        if(s1[i] == '*') d++;
        if(s2[i] == '*') x++;
    }

    
    printf("%.2lf\n", (d-x)/d);
}