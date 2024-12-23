#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int odd = 0, even =0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if(x % 2) odd ++;
        else even ++;
    }

    if(even > odd){
        cout << 2*odd + 1 << endl;
        return 0;
    }    

    int ans = 2 * even;

    int exceeding_odd = odd - even;

    while(exceeding_odd){
        if(exceeding_odd >= 2){
            ans ++;
            exceeding_odd -= 2;
        } else{
            break;
        }
        if(exceeding_odd >= 1){
            ans ++;
            exceeding_odd --;
        }
    }
    if(exceeding_odd) ans --;
    
    cout << ans << endl;
}