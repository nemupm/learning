#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>

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
const int MAX_K = 100000;
int n;
int a[MAX_N], m[MAX_N];
int K;
// dp[x+1][y]: boolean; whether 0 .. x items can create y or not
bool dp[MAX_N+1][MAX_K+1];

bool solve(){
    fill(dp[0], dp[0] + (MAX_N + 1) * (MAX_K + 1), false);
    dp[0][0] = true;
    REP(i, n){
        REP(j, K+1){
            for (int k = 0; k <= m[i] && k * a[i] <= j; ++k) {
                dp[i+1][j] |= dp[i][j - k * a[i]];
            }
        }
    }
    return dp[n][K];
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,n) cin >> a[i];
    REP(i,n) cin >> m[i];
    cin >> K;
    cout << (solve() ? "Yes" : "No") << "\n";
    return 0;
}
