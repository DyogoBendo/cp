#include <bits/stdc++.h>

using namespace std;

int fib(int n){
    int a  = 1;
    int b = 1;
    for (int i = 2; i <= n; i++)
    {        
        int c = a;
        a = a + b;        
        b = c;
    }

    return a;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >>n >> x >> y;

        int x0 = 1;
        int xf = fib(n); // altura maxima
        int y0 = 1;
        int yf = fib(n + 1); // largura maxima


        int possible = 1;
        int situation = 0; 
        while(xf - x0 && yf - y0){
            if(situation){                
                if(x > x0 + (yf - y0) || x < xf - (yf - y0)){
                    situation = 0;
                    if(x > x0 + (yf - y0)){
                        x0 += (yf - y0 + 1);
                    } else{
                        xf -= (yf - y0 + 1);
                    }
                } else{
                    possible = 0;
                    break;
                }

            } else{
                if(y > y0 + (xf - x0) || y < yf - (xf - x0)){
                    situation = 1;
                    if(y > y0 + (xf - x0)){
                        y0 += (xf - x0 + 1);
                    } else{
                        yf -= (xf - x0 + 1);
                    }
                } else{
                    possible = 0;
                    break;
                }
            }
        }

        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
}