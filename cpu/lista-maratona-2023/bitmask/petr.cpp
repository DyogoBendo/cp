#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> values(n);

    for(int i = 0; i < n; i++) cin >> values[i];

    int possibilities = 0;
    for(int i = 0; i < (1 << n) - 1; i ++){
        int total = 0;
        for (int j = 0; j < n; j++)
        {
            if((1 << j) & i){
                total += values[j];                
            } else{                
                total -= values[j];
            }
        }
        
        total = total % 360;
        if(!total){            
            possibilities += 1;
        }        
    }

    if(possibilities){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}