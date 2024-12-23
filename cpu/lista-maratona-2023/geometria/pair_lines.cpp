#include <bits/stdc++.h>

using namespace std;

long long x[100001];
long long y[100001];
long long line[100001];
int n;

int exists_line(int p1, int p2){    
    for (int i = 1; i <= n; i++)
    {
        line[i] = (x[p1] - x[p2]) * (y[p2] - y[i]) == (x[p2] - x[i]) * (y[p1]  - y[p2]);        
    }

    int line2 = 0, line3 = 0;
    for (int i = 1; i <= n; i++)
    {        
        if(!line[i]){
            if(!line2){
                line2 = i;                
            } else{
                if(!line3) {
                    line3 = i;
                } else{
                    if((x[line2] - x[line3]) * (y[line3] - y[i]) != (x[line3] - x[i]) * (y[line2] - y[line3])){
                        return 0;
                    }
                }
            }
        }
    }    

    return 1;
    
    
}

int main(){    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    if(n <= 3){
        cout << "YES"  << endl;
    } else{                
        if(exists_line(1, 2) || exists_line(1, 3) || exists_line(2, 3)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}