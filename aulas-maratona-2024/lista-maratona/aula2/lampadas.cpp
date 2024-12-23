#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        if(c == 2) b = ~b;
        a = ~a; 
    }
       
    cout <<-1 * a << endl << -1 * b << endl;
}