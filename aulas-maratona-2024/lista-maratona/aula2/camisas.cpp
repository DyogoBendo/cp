#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int v[3] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        v[x] ++;
    }

    for (int i = 0; i < 3; i++)
    {
        int x;
        cin >> x;
        if(x < v[i]){
            cout << "N" << endl;
            return 0;
        }
    }
    
    cout  << "S" << endl;
       
}