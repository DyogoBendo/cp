#include <bits/stdc++.h>

using namespace std;

void p(int n){
    if(n == 0){
        cout << "*" << endl;
        return;
    }
    for (int i = 0; i < n && i < 5; i++)
    {
        cout << "I";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    p(n);
    
    int k = n > 5 ? n - 5 : 0;

    p(k);
    
}