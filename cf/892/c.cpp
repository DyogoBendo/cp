#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    long long best_result = -1;
    int inversion = n;

    while(inversion > -1){        
        long long current_result = 0;
        long long biggest = 0;
        int i = 1;
        for (; i <= inversion; i++)
        {                     
            long long r = i *i;
            current_result += r;
            if(r > biggest) biggest = r;
        }        

        for (int j = 0; i <= n; i ++, j++)
        {            
            long long r = i *(n - j);
            current_result += r;
            if(r > biggest) biggest = r;
        }
        current_result -= biggest;        
        best_result = max(best_result, current_result);
        inversion --;                
    }

    cout << best_result << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}