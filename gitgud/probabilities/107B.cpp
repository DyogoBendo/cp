#include <cstdio>
 
int s[1010];
 
int main(){
    int n, m, h;
    int total = 0;
    scanf("%d%d%d", &n, &m, &h);
    for(int i = 1; i <= m; i++){
        scanf("%d", &s[i]);
        total += s[i];
    }
    
    if(total < n){
        printf("-1\n");
    }else{
        double p = 1;
        total--;
        s[h]--;
        for(int i = 0; i < s[h]; i++){
            p /= (total-i);
            p *= (total-n+1-i);
        }
        p = 1.0 - p;
        printf("%.9lf\n", p);
    }
    
    
    return 0;
}