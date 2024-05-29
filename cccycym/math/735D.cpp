#include <bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1E5 + 10, mod = 1E9 + 7;

bool is_prime(LL n)
{
    for(LL i = 2; i * i <= n; i ++ )
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    LL n;
    cin >> n;
    if(is_prime(n)) cout << 1 << endl;
    else if(n % 2 == 0) cout << 2 << endl;
    else
    {
        if(is_prime(n - 2)) cout << 2 << endl;
        else cout << 3 << endl;
    }

    return 0;
}