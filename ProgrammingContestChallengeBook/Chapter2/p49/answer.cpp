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

const int MAX_N = 20000;
int n;
int l[MAX_N];

int solve(){
    int ans = 0;
    REP(i,n-1){
        sort(l+i,l+n);
        ans += l[i] + l[i+1];
        l[i+1] = l[i] + l[i+1];
    }
    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,n) cin >> l[i];
    cout << solve() << "\n";
    return 0;
}
