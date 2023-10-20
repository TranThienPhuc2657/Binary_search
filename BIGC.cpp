#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define FOR(i,n) for (int i=0; i<n; i++)
#define FORD(i,n) for (int i=n-1; i>=0; i--)
#define pb push_back
#define fi first
#define se second
using ll=long long;
const int N=1e6+5;

int n,m,a[N];

bool check(int k) {
    vector <int> b(k,m);
    int j=0;
    FOR(i,n) {
        while (b[j]<a[i] and j<k) j++;
        if (j==k) return false;
        b[j]-=a[i];
    }
    return true;
}

int bin_search() {
    int lo=1, hi=n;
    while (lo<hi) {
        int mid=lo+(hi-lo)/2;
        if (check(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("BIGC");

    cin >> n >> m;
    FOR(i,n) cin >> a[i];
    sort(a,a+n);
    cout << bin_search();
    return 0;
}
