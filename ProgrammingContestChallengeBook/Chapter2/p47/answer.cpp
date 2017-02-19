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

const int MAX_N = 1000;
int N,R;
int x[MAX_N];

int solve(){
    sort(x, x+N);
    int i = 0, ans = 0;

    while(i < N){
        // s is the leftmost point not being covered
        int s = x[i];
        while(i < N && x[i] <= s + R) i++;
        // p is the point to be marked
        int p = x[i-1];
        eprintf("marked %d\n", p);
        while(i < N && x[i] <= p + R) i++;

        ans++;
    }

    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N; cin >> R;
    REP(i,N) cin >> x[i];
    cout << solve() << "\n";
    return 0;
}
