/*
 * Solution Template for Backpacking
 * 
 * Australian Informatics Olympiad 2024
 * 
 * This file is provided to assist with reading and writing of the input
 * files for the problem. You may modify this file however you wish, or
 * you may choose not to use this file at all.
 */

#include <bits/stdc++.h>

using namespace std;

/* N is the number of towns. */
int N;

/* K is the maximum number of cans that Norman can fit in his backpack. */
int K;

/*
 * D contains the distances between the towns. Note that the array starts from
 * 0, and so the values are D[0] to D[N-2].
 */
int D[200005];

/*
 * C contains the cost of food in each town. Note that the array starts from 0,
 * and so the values are C[0] to C[N-1].
 */
int C[200005];

int answer;
int main(void) {
    /* Open the input and output files. */
    FILE *input_file = fopen("backin.txt", "r");
    FILE *output_file = fopen("backout.txt", "w");

    /* Read the values of N, K, D, and C from the input file. */
    fscanf(input_file, "%d%d", &N, &K);
    for (int i = 0; i < N-1; i++) {
        fscanf(input_file, "%d", &D[i]);
    }
    for (int i = 0; i < N; i++) {
        fscanf(input_file, "%d", &C[i]);
    }

    vector<int> location(N);
    location[0] = 0;


    for (int i = 0; i < N - 1; i++)
    {
        location[i + 1] = location[i] + D[i];
    }

    map<int, int> nextsmall;
    stack<pair<int, int>> stillsmall; 

    for (int i = 0; i < N; i++)
    {
        while(!stillsmall.empty() && stillsmall.top().first > C[i]){
            nextsmall[stillsmall.top().second] = i;
            stillsmall.pop();
        }
        stillsmall.push({C[i], i});
    }
       
    int k = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int kprev = k;

        if(nextsmall[i]){
            int toreach = nextsmall[i];
            int curdist = location[toreach] - location[i];
            if(k < curdist) k = min(K, curdist);
        } else{
            k = min(location[N-1] - location[i], K);
        }
        answer += (k - kprev) * C[i];
        k -= location[i + 1] - location[i];
    }

    /* Write the answer to the output file. */
    fprintf(output_file, "%d\n", answer);

    /* Finally, close the input/output files. */
    fclose(input_file);
    fclose(output_file);

    return 0;
}