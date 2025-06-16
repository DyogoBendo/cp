#include <bits/stdc++.h>

using namespace std;

int conta[10];
int main(){    

    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        conta[x] ++;
    }

    for (int i = 0; i < 10; i++)
    {
        if(conta[i] > 4){
            cout << "N" << endl;
            return 0;
        }
    }
        
    cout << "S" << endl;
}