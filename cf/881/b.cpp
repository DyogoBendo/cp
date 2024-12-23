#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n;

    cin >> t;

    while(t){
        t --;
        cin >> n;
        long long total = 0, operations = 0, x;
        int negative_sequence = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if(x > 0){
                total += x;
                negative_sequence = 0;
            } else if(x < 0){
                if(!negative_sequence){
                    operations ++;
                    negative_sequence = 1;
                }
                total += -x;
            }
        }
        cout << total << " " << operations << endl;
    }
    
    
}