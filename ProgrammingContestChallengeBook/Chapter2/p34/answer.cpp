#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define all(x) (x).begin(),(x).end()

typedef long long ll;

using namespace std;

int a[20];
int n, k;

bool dfs(int i, int sum){
    if(i == n) return sum == k;

    if(dfs(i + 1, sum)) return true;

    if(dfs(i + 1, sum + a[i])) return true;

    return false;
}

int main() {
	// to shorten time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,4) cin >> a[i];
    cin >> k;

    if(dfs(0, 0)) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}
