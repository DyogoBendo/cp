#include <bits/stdc++.h>

using namespace std;


struct point
{
    int x, y;

    int calculateSquaredDistances(point b){        
        return ((x - b.x) * (x - b.x)) + ((y - b.y) * (y - b.y));
    }

    // check if A this point is perpendicular with B this point
    bool isPerpendicular(point a, point b){
        return y * (-a.y - b.y + y) + (a.y * b.y) == -(x * (x - a.x - b.x) + (a.x * b.x));
    }
};

struct shape{
    point pointA, pointB, pointC, pointD;
    int distances[4][4];

    shape(point points[4]){
        pointA = points[0];
        pointB = points[1];
        pointC = points[2];
        pointD = points[3];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {                
                distances[i][j] = points[i].calculateSquaredDistances(points[j]);
            }            
        }        
    }

    bool isSquare(){
        int distanceAB = distances[0][1];
        int distanceAC = distances[0][2];
        int distanceAD = distances[0][3];
        int distanceBC = distances[1][2];
        int distanceBD = distances[1][3];
        int distanceCD = distances[2][3];        

        if(distanceAB == distanceAC && distanceAD == 2 * distanceAB){
            if(distanceBD == distanceCD && distanceAB == distanceBD){
                return true;
            }
        }
        if(distanceAB == distanceAD && distanceAC == 2 * distanceAB){
            if(distanceBC == distanceCD && distanceBC == distanceAB){
                return true;
            }
        }
        if(distanceAC == distanceAD && distanceAB == 2 * distanceAC){
            if(distanceBC == distanceBD && distanceBC == distanceAC){
                return true;
            }
        }
        return false;
    }

    bool isRectangle(){
        int distanceAB = distances[0][1];
        int distanceAC = distances[0][2];
        int distanceAD = distances[0][3];
        int distanceBC = distances[1][2];
        int distanceBD = distances[1][3];
        int distanceCD = distances[2][3];

        if(distanceAD == distanceAB + distanceAC){
            bool bAc = pointA.isPerpendicular(pointB, pointC);
            bool bDc = pointD.isPerpendicular(pointB, pointC);
            return bAc && bDc && distanceCD == distanceAB && distanceBD == distanceAC;
        }        
        if(distanceAC == distanceAB + distanceAD){
            bool bAd = pointA.isPerpendicular(pointB, pointD);
            bool bCd = pointA.isPerpendicular(pointB, pointD);

            return bAd && bCd && distanceAD == distanceBC && distanceAB == distanceCD; 
        }
        if(distanceAB == distanceAC + distanceAD){
            bool cAd = pointA.isPerpendicular(pointC, pointD);
            bool cBd = pointB.isPerpendicular(pointC, pointD);

            return cAd && cBd && distanceAC == distanceBD && distanceAD == distanceBC;
        }
        return false;
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sp, rp;
    int found = 0;
    point points[8];
    for (int i = 0; i < 8; i++)
    {
        int x, y;
        cin >> x >> y;
        points[i] = point{x, y};
    }

    string answer = "NO";
    int squareAnswer[4];
    int rectangleAnswer[4];
    // checar todas as combinações possíveis de pontos


    int visited[8] = {0};
    for (int i = 0; i < 8; i++)
    {
        if(found) break;
        visited[i] = 1;
        for (int j = i + 1; j < 8; j++)
        {
            if(found) break;
            visited[j] = 1;
            for (int k = j + 1; k < 8; k++)
            {
                if (found) break;
                visited[k] = 1;
                for (int l = k + 1; l < 8; l++)
                {
                    if(found) break;
                    visited[l] = 1;          

                    point squarePoints[4];
                    point rectanglePoints[4];

                    sp = 0;
                    rp = 0;                    
                    for (int m = 0; m < 8; m++)
                    {                                                                
                        if(visited[m]){                               
                            squarePoints[sp] = points[m];
                            sp ++;
                        } else{                      
                            rectanglePoints[rp] = points[m];
                            rp ++;
                        }                        
                    }                        
                    
                    shape square = shape(squarePoints);
                    shape rectangle = shape(rectanglePoints);
                    
                    sp = 0; 
                    rp = 0;
                    if(square.isSquare() && rectangle.isRectangle()){
                        answer = "YES";                        
                        for (int m = 0; m < 8; m++)
                        {
                            if(visited[m]){
                                squareAnswer[sp] = m;
                                sp ++;
                            } else{
                                rectangleAnswer[rp] = m;
                                rp ++;
                            }
                        }
                        found = 1;
                    }
                    visited[l] = 0;

                }
                visited[k] = 0;
                
            }            
            visited[j] = 0;
        }
        visited[i] = 0;
                
    }

    if(answer == "NO"){
        cout << answer << endl;
    } else{
        cout << "YES" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << squareAnswer[i] + 1 << " ";
        }
        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << rectangleAnswer[i] + 1 << " ";
        }
        cout << endl;
        
    }
    
    
}