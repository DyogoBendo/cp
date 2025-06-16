#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int p1 = 0, m1 = 0, p2, m2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 1) p1 ++;
        else m1 ++;
    }    

    cin >> p2 >> m2;

    if(p1 > p2 || m1 > m2){
        cout << "N" << endl;
    } else{
        cout << "S" << endl;
    }
    
}