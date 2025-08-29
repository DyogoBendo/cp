#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    string s;
    cin >> s;

    int gl = 0, gr = 0, pl = 0, pr = 0, curr = 0;

    auto print_score = [&](){
        if(gl < 2 and gr < 2){
            cout << gl << " (" << pl << (curr == 0 ? "*" : "") << ")" << " - " << gr << " (" << pr << (curr == 1 ? "*" : "") << ")" << endl;
        } else{
            cout << gl << (curr == 0 ? " (winner)" : "") << " - " << gr << (curr == 1 ? " (winner)" : "") << endl;
        }
    };

    auto reset = [&](){
        pl = 0, pr = 0;
    };

    auto solve_game = [&](){
        if(curr == 0) pl ++; else pr++;
        if(pl == 10) gl++, reset();
        else if(pr == 10) gr++, reset();
        else if(pl - pr >= 2 && pl >= 5) gl++, reset();
        else if(pr - pl >= 2 && pr >= 5) gr++, reset();
    };
    
    for(auto c : s){
                
        if(c == 'Q') print_score();
        else{
            if(c == 'R') curr ^= 1;
            solve_game();
            
        }        
        
    }
}