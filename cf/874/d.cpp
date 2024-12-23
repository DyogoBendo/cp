#include <bits/stdc++.h>

using namespace std;

int a[2000];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int max_v = 0, l = 0, r = 0;


        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] > max_v && i) {
                max_v = a[i]; 
                r = i;
            }
        }

        if(n == 1){
            cout << 1 << endl;
            continue;
        }

        if(r == n - 1){
            if(a[0] >= a[n - 2]){
                cout << a[r];
                for(int i = 0; i < n - 1; i++) cout << " " << a[i];
                cout << endl;
                continue;
            }
        }

        r--;
        l = r;
        while(l > 0 && a[l - 1] > a[0]) l--;        

        for (int i = r + 1; i < n; i++)
        {            
            cout << a[i] << " ";
        }
        for (int i = r; i >= l; i--)
        {
            cout << a[i] << " ";
        }
        for (int i = 0; i < l; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
                
    }
}