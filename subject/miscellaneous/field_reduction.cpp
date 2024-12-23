#include <bits/stdc++.h>

using namespace std;

#define int long long

const int NMAX=1e5;
const int INF = 2e9;

int n;

int x[NMAX];
int y[NMAX];

struct Analysis{
    int area;
    vector<vector<int>> borders;
};

Analysis analyze(vector<int> indicesToSkip){
    int minX = INF, minY = INF, maxX = -INF, maxY = -INF;

    for (int i = 0; i < n; i++)
    {
        bool skip = false;
        for (int k : indicesToSkip)
        {
            if(k == i) skip = true;
        }
        if(skip) continue;

        minX = min(minX, x[i]);
        minY = min(minY, y[i]);
        maxX = max(maxX, x[i]);
        maxY = max(maxY, y[i]);        
    }

    Analysis a;

    a.area = (maxX - minX) * (maxY - minY);

    vector<int> up, down, left, right;

    for (int i = 0; i < n; i++)
    {
        bool skip = false;
        for (int k : indicesToSkip)
        {
            if(k == i) skip = true;
        }
        if(skip) continue;

        if(x[i] == minX) left.push_back(i);
        if(x[i] == maxX) right.push_back(i);
        if(y[i] == minY) down.push_back(i);
        if(y[i] == maxY) up.push_back(i);
    }
    
    if(up.size() <= 3) a.borders.push_back(up);
    if(down.size() <= 3) a.borders.push_back(down);
    if(left.size() <= 3) a.borders.push_back(left);
    if(right.size() <= 3) a.borders.push_back(right);    

    return a;
}

signed main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    scanf("%lld", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x[i]);
        scanf("%lld", &y[i]);
    }

    Analysis a = analyze(vector<int>());

    int bestArea = a.area;

    for (auto pointsOnBorder : a.borders)
    {   
        Analysis smallerAnalysis = analyze(pointsOnBorder);
        bestArea = min(bestArea, smallerAnalysis.area);
        for (auto pointsOnBorder2 : smallerAnalysis.borders)
        {
            if(pointsOnBorder2.size() + pointsOnBorder.size() <= 3 ){
                for (auto p : pointsOnBorder)
                {
                    pointsOnBorder2.push_back(p);
                }
                Analysis analysis3 = analyze(pointsOnBorder2);

                bestArea = min(bestArea, analysis3.area);
                for (auto pointsOnBorder3 : analysis3.borders)
                {
                    if(pointsOnBorder3.size() + pointsOnBorder2.size() <= 3){
                        for (auto p : pointsOnBorder2)
                        {
                            pointsOnBorder3.push_back(p);
                        }

                        Analysis analysis4 = analyze(pointsOnBorder3);
                        bestArea = min(bestArea, analysis4.area);                        
                    }
                }                                
            }
        }
        
    }

    printf("%lld\n", bestArea);
    
}
