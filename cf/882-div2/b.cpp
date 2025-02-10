#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> values;
    int smallest_value = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(smallest_value == -1) smallest_value = x;
        else smallest_value &= x;
        values.push_back(x);
    }
    int groups = 0;

    if(smallest_value != 0) groups = 1;
    else{
         
    int i = 0;
    int j = 0;

    int current = values[0];    

    
    while(j < n){        
        current &= values[j];        
        if(current == smallest_value){            
            i = j + 1;
            j = i;
            groups ++;  
            if( i < n) current = values[i];   
        } else{
            j ++;
        }
    }   
    }
     

    cout << groups << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}