#include <bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1E5 + 10, mod = 1E9 + 7;

bool check(vector<int> &a, int k)
{
    int GCD = 0;
    for(int i = 0; i + k < a.size(); i ++ )
        GCD = gcd(GCD, abs(a[i + k] - a[i]));
    return GCD != 1;
}

void run()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    for(int k = 1; k <= n; k ++ )
        if(n % k == 0 && check(a, k))
            ans ++;
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}