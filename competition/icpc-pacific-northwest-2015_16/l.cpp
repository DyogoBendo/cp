#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

double w;
double happy(double money){
    return log(1 + (money / w));
}

signed main(){
    int n;
    cin >> n >> w;

    vector<tuple<string, double, int>> questions;        

    for (int i = 0; i < n; i++)
    {
        string s;
        double d;
        int v;
        cin >> s >> d >> v;
        questions.push_back({s, d, v});                
    }
    
    int curr_safe = 0;
    double curr_prob = 1;
    double ex = 0;    
    double best = 0;
    for (int i = 0; i < n; i++)
    {  
        double p = get<1>(questions[i]);
        double q = 1 - p;        
        
        double correct = curr_prob * p;
        double wrong = curr_prob * q;                
        curr_prob *= p;

        double correct_happy = correct * happy(get<2>(questions[i]));
        double wrong_happy = wrong * happy(curr_safe);

        best = max(best, correct_happy + wrong_happy + ex);
        ex += wrong_happy;

        if(get<0>(questions[i]) == "safe"){
            curr_safe = get<2>(questions[i]);
        }
    }
            
    
    double ans = w * (exp(best) - 1);

    printf("$%.2Lf\n", ans);
}