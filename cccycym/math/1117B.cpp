#include <bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1E5 + 10, mod = 1E9 + 7;

int main()
{
    LL n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    cout << (a[0] * (k) + a[1]) * (m / (k + 1)) + a[0] * (m % (k + 1));


    return 0;
}