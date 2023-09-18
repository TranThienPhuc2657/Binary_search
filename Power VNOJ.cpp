#include <bits/stdc++.h>
using namespace std;

using ll=long long;

ll l,r;

bool check(ll x, int k) {
    if (pow(x,k)>=l)
        return true;
    else return false;
}

ll bin_search(ll left, ll right, int k) {
    while (left<right) {
        ll mid=left+(right-left)/2;
        if (check(mid,k))
            right=mid;
        else left=mid+1;
    }
    return left;
}

void solve(int num) {
    cin >> l >> r;
    for (int k=40; k>=1; k--) {
        //the limit of the result is 40 because 2^40 > 10^12
        //binary search for the smallest x^k larger than l then compare it to r, if it is smaller then print it out
        //cause we run a loop from the limit to 1
        //left is 1 and right is r^(1/k). Right is the largest possible number (n) such that n^k<=r.
        //For example with k=2: ( n^(1/2) )^2= sqrt(n)^2 = n.
        //Since x is an integer so we can't just print 40 in every test.
        //Not every time pow(r,1.0/k)+1 will give the right x
        //For example with l=2, r=2 and k=40. pow(r,1.0/k) will be 1 and 1^40 = 1 is not larger than 2 (l)
        //Also pow(r,1.0/k) is rounded down so we have to plus 1 for accuracy in binary search (pow(r,1.0/k)+1)
        //If not, the test 10^12 and 10^12 will be wrong because pow(10^12,1.0/12) will only return 9 (not 10) (idk some computer mistake
        //when calculate with decimal number i guess like 9.99999999999 will be rounded to 9)
        ll temp=pow(bin_search(1,pow(r,1.0/k)+1,k),k);
        if (temp>=l and temp<=r) {
            printf("Case #%d: %d\n",num,k);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i=1; i<=t; i++)
        solve(i);
    return 0;
}

