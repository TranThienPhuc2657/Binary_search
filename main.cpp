#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll l, r;
int t;

bool check(ll k) {
    for (int i=1; pow(i,k)<=r; i++) {
        ll temp=pow(i,k);
        if (temp>=l and temp<=r)
            return true;
    }
    return false;
}

ll bin_search(ll lo, ll hi) {
    while (lo<hi) {
        ll mid=lo+(hi-lo+1)/2;
        if (check(mid)) {
            lo=mid;
        }
        else hi=mid-1;
    }
    return lo;
}

void solve(int num) {
    cin >> l >> r;
    printf("Case #%d: %d\n",num,bin_search(1,sqrt(r)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i=1; i<=t; i++)
        solve(i);
    return 0;
}
