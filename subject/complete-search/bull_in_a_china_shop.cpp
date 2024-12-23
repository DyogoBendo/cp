#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("bcs");
    int n, k;
    cin >> n >> k;

    vector<vector<char>> original(n, vector<char>(n));

    vector<vector<vector<char>>> pieces(k, vector<vector<char>>(n, vector<char>(n)));
    vector<int> hashtags (k, 0);

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cin >> original[a][b];
        }
        
    }

    for (int a = 0; a < k; a++)
    {
        for (int b = 0; b < n; b++)
        {
            for (int c = 0; c < n; c++)
            {         
                char p;
                cin >> p;       
                pieces[a][b][c] = p;
                if(p == '#') hashtags[a] ++;
            }
            
        }
    }
    int ans1, ans2;
    for (int a = 0; a < k; a++)
    {
        vector<vector<char>> c1 = pieces[a];
        // primeiro elemento do par
        for (int b = a + 1; b < k; b ++)
        {
            vector<vector<char>> c2 = pieces[b];
            // segundo elemento do par

            for (int c = -n + 1; c < n; c++)
            {
                // mover o primeiro horizontalmente
                for (int d = -n + 1; d < n; d++)
                {
                    // mover o primeiro verticalmente
                    for (int e = -n + 1; e < n; e++)
                    {
                        // mover o segundo horizontalmente
                        for (int f = -n + 1; f < n; f++)
                        {
                            // mover o segundo verticalmente
                            vector<vector<char>> p1(n, vector<char>(n, '.'));
                            vector<vector<char>> p2(n, vector<char>(n, '.'));

                            int valid = 1;
                            //cout << "a, b: " << a << " " << b << endl;
                            //cout << "c, d, e, f: " << c << " " << d << " " << e << " " << f << endl;
                            for (int g = 0; g < n; g++)
                            {
                                int valid1 = 1;
                                for (int h = 0; h < n; h++)
                                {
                                    if(c1[g][h] == '#'){
                                        if( g + c >= n || h + d >= n || g + c < 0 || h + d < 0 ){
                                            valid1 = 0;
                                            break;
                                        } else{
                                            //cout << "g, h: " << g << " " << h << endl;
                                            // cout << "p1: insert hastag at: " << g+ c << " " << h+d << endl;
                                            p1[g+c][h+d] = '#';
                                        }
                                    }

                                }
                                if(!valid1){
                                    valid = 0;
                                    break;
                                }
                                
                            }
                            for (int g = 0; g < n; g++)
                            {
                                int valid2 = 1;
                                for (int h = 0; h < n; h++)
                                {
                                    if(c2[g][h] == '#'){
                                        if( g + e >=n || h + f >= n || g + e < 0 || h + f < 0){
                                            valid2 = 0;
                                            break;
                                        } else{
                                            p2[g+e][h+f] = '#';
                                        }
                                    }
                                }
                                if(!valid2){
                                    valid = 0;
                                    break;
                                }
                                
                            }

                            if(!(valid)) continue;

                            vector<vector<char>> p3(n, vector<char>(n, '.'));
                            for (int g = 0; g < n; g++)
                            {
                                for (int h = 0; h < n; h++)
                                {
                                    if(p1[g][h] == p2[g][h] && p1[g][h] == '#'){
                                        valid = 0;
                                        break;
                                    }
                                    if(p1[g][h] == '#' || p2[g][h] == '#') p3[g][h] = '#';                                    
                                }
                                if(!valid) break;                                
                            }
                            
                            if(!(valid)) continue;
                            
                            

                            for (int g = 0; g < n; g++)
                            {
                                for (int h = 0; h < n; h++)
                                {
                                    if(p3[g][h] != original[g][h]){
                                        valid = 0;
                                        break;
                                    }                 
                                }
                                if(!valid) break;                                
                            }

                            if(valid){
                                ans1 = a;
                                ans2 = b;
                            }


                        }
                        
                    }
                    
                }
                
            }
            
        }
           
    }

    cout << ans1 + 1 << " " << ans2 + 1 << endl;
    
}