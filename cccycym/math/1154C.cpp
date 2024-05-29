#include <bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1E5 + 10, mod = 1E9 + 7;

int solve(string s, int a, int b, int c)
{
    int w = min(a / 3, min(b / 2, c / 2));
    int res = w * 7;
    a -= w * 3;
    b -= w * 2;
    c -= w * 2;

    int x[4] = {0, a, b, c};
    for(int i = 0; i < 7; i ++ )
    {
        if(x[s[i] - '0']) res ++, x[s[i] - '0'] --;
        else break;
    }

    return res;
}

int main()
{
    int a, b, c, res = 0;
    cin >> a >> b >> c;

    string s = "1231321";
    for(int i = 0; i < 7; i ++ )
    {
        s = s.substr(1) + s[0];
        res = max(res, solve(s, a, b, c));
    }

    cout << res;

    return 0;
}