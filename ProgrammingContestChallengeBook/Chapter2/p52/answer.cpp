#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;
int n,W;
int w[MAX_N], v[MAX_N];
// dp[x][y]: max total values when you choose some items from ones
// whose index is x ~ n-1 items on the condition their total weights are less than y
int dp[MAX_N + 1][MAX_W + 1];

int rec(int i, int j){
    if(dp[i][j] >= 0){
        return dp[i][j];
    }

    int res;
    if(i == n){
        res = 0;
    }
    else if(w[i] > j){
        res = rec(i+1,j);
    }
    else{
        res = max(rec(i+1, j), rec(i+1, j-w[i]) + v[i]);
    }
    dp[i][j] = res;
    return res;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,n) cin >> w[i];
    REP(i,n) cin >> v[i];
    cin >> W;

    memset(dp,-1,sizeof(dp));
    cout << rec(0,W) << "\n";
    return 0;
}
