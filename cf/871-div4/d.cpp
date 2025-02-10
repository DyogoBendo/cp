#include <bits/stdc++.h>

using namespace std;

bool check(int n, int m){          
    if(n == m) return true;    
    if(m > n || n % 3) return false;

    int a  = n / 3;
    return check(2 * a, m) || check(a, m);
}

int main(){
    
    int t;
    cin >> t;
    while(t--){        
        int n, m;
        scanf("%d %d", &n, &m);                        
            
        if(check(n, m)){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
        
    }
}