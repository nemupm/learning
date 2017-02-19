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

const int MAX_N = 2000;
int n;
char s[MAX_N];
char t[MAX_N];

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,n) cin >> s[i];

    int l = 0, r = n-1;
    while(l <= r){
        bool left = false;
        REP(i,n){
            if(s[l+i] > s[r-i]){
                left = false;
                break;
            }
            else if(s[l+i] < s[r-i]){
                left = true;
                break;
            }
        }
        if(left) putchar(s[l++]);
        else putchar(s[r--]);
    }

    putchar('\n');
    return 0;
}
