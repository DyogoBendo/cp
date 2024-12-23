#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long n;
    cin >> n;
 
    long long sum = (n + 1) * n / 2;
 
    if(sum % 2) cout << "NO";
    else{
        vector<int> values (n + 1, 0);
 
        long long current = sum / 2;
        int marked = 0;
        for(int i = n; i > 0; i--){
            if(current - i >= 0){
                marked  ++;
                current -= i;
                values[i] = 1;
            }
        } 
        if(current) cout << "NO";
        else{
            cout << "YES" << endl;
            cout << marked << endl;
            for (int i = 1; i <= n; i++)
            {
                if(values[i]) cout << i << " ";
            }
            cout << endl;
            cout << n - marked << endl;
            for (int i = 1; i <= n; i++)
            {
                if(!values[i]) cout << i << " ";
            }
            
        }
    }
    cout << endl;
    
}
