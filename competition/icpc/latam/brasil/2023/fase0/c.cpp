#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    int r = 2 * n - sqrt(k) + 1;
    
    cout << "----------" << endl;
    for (int i = 1; i < 2 * n + 1; i++)
    {
        int i2 = i * i;

        for (int j = 1; j < 2 * n + 1; j++)
        {
            if(i == j ) continue;

            int j2 = j * j;                        

            if(abs(i2 - j2) % (2 * n + 1) == 0){
                cout << i << " " << j << endl;
            }
        }
        
        cout << "---------" << endl;
    }
    

    cout << r * r << endl;
}