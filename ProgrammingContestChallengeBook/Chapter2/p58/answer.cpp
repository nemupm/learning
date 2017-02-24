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
int n;
int w[MAX_N], v[MAX_N];
int W;
int dp[MAX_N][MAX_W];

int solve(){
//    REP(i,n) dp[i][0] = 0;
    REP(j,W+1) dp[0][j] = 0;
    REP(i,n){
        REP(j,W+1){
            for (int k = 0; k * w[i] <= j; ++k) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j - k * w[i]] + k * v[i]);
            }
        }
    }
    return dp[n][W];
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,n) cin >> w[i];
    REP(i,n) cin >> v[i];
    cin >> W;

    cout << solve() << "\n";
    return 0;
}
