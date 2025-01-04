// https://dmoj.ca/problem/coci17c5p2

#include <bits/stdc++.h>

using namespace std;
const int MAXNM = 51;
const int INF = 1e6;
int n, m, k;
int ans[MAXNM][MAXNM];

void update(int x, int y, int v){
    if(x < 1) return;
    if(y < 1) return;
    if(x > m) return;
    if(y > n) return;
    ans[y][x] = min(ans[y][x], v);
}

void add(int row, int column, int d){
    int minx = column;
    int maxx = column;
    int miny = row;
    int maxy = row;

    int currx = column;
    int curry = row;
    int currd = 0;

    update(currx, curry, 1);
    int step = 1;

    while(minx >= 1 or maxx <= m or miny >= 1 or maxy <= n){        
        if(currd == 0){
            while(curry >= miny){
                step ++;
                curry --;
                update(currx, curry, step);                
            }            
            miny --;                        
            currd = 1;
        } else if(currd == 1){            
            if(d == 0){                
                while(currx <= maxx){
                    currx ++;
                    step ++;
                    update(currx, curry, step);
                }
                maxx ++;
            } else{
                while(currx >= minx){
                    step ++;
                    currx --;
                    update(currx, curry, step);
                }
                minx --;
            }
            currd = 2;
        } else if(currd == 2){
            while(curry <= maxy){
                step ++;
                curry ++;
                update(currx, curry, step);
            }
            maxy ++;
            currd = 3;
        } else{
            if(d == 1){
                while(currx <= maxx){
                    currx ++;
                    step ++;
                    update(currx, curry, step);
                }
                maxx ++;
            } else{
                while(currx >= minx){
                    step ++;
                    currx --;
                    update(currx, curry, step);
                }
                minx --;
            }
            currd = 0;
        }        
    }    
}

int main(){
    cin >> n >> m >> k;        

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans[i][j] = INF;
        }
        
    }
    

    for (int i = 0; i < k; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        add(x, y, d);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;        
    }    
}