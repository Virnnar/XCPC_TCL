#include <bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1E5 + 10, mod = 1E9 + 7;

void run()
{
    LL x, y, z, t;
    cin >> x >> y;
    z = x ^ y;
    for (int i = 0; i < 31; i++)
    if (z >> i & 1ll)
    {
        cout << (1ll << i) << endl;
        break;
    }

}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}

