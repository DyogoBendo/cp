#include <bits/stdc++.h>

using namespace std;

struct circle
{
    int x, y, r;
    bool possible;
    circle(){}
    circle(int a, int b, int c){
        x = a;
        y = b;
        r = c;
        possible = 1;
    }
};


int main(){
    int r, d;
    vector<circle> sausages;
    cin >> r >> d;
    int pizza = r - d;

    int n;
    cin >> n;

    int result = 0;

    for(int i = 0; i < n; i++){
        int x, y, radius;
        cin >> x >> y >> radius;
        sausages.push_back(circle(x, y, radius));
    }

    // verificar se há intersecção com a pizza

    for (int i = 0; i < n; i++)
    {        
        circle *s = &sausages[i];
        int dist = (s->x * s->x) + (s->y * s->y);

        if(dist < (s->r + pizza) * (s->r + pizza)){            
            s->possible = 0;            
        }
    }

    for (int i = 0; i < n; i++)
    {        
        circle *s = &sausages[i];          
        int dist = (s->x * s->x) + (s->y * s->y);
        if(dist <= (r - s->r) * (r - s->r) && s->possible){            
            result ++;
        }
    }
    
    cout << result << endl;

}