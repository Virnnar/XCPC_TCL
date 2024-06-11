#include <bits/stdc++.h>
#define ULL unsigned long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1E5 + 10, p = 131;

ULL get(vector<ULL> &H, vector<ULL> &P, int l, int r)
{
    return H[r] - H[l - 1] * P[r - l + 1];
}

void run()
{
    int n, k;
    cin >> n >> k;
    char s[N], s1[N], s2[N];
    memset(s, 0, sizeof s);
    memset(s1, 0, sizeof s1);
    memset(s2, 0, sizeof s2);
    cin >> s + 1;

    vector<ULL> H(N), I(N), P(N);

    P[0] = 1;
    for(int i = 1; i <= n; i ++ )
    {
        H[i] = H[i - 1] * p + s[i];
        I[i] = I[i + 1] * p + s[n - i + 1];
        P[i] = P[i - 1] * p;
    }

    for(int i = 1; i <= n; i ++ )
    {
        if(((i - 1) / k) & 1) s1[i] = '0', s2[i] = '1';
        else s1[i] = '1', s2[i] = '0';
    }

    ULL w1 = 0, w2 = 0;
    for(int i = 1; i <= n; i ++ )
    {
        w1 = w1 * p + s1[i];
        w2 = w2 * p + s2[i];
    }

    for(int i = 1; i <= n; i ++ )
    {
        ULL w = get(H, P, i + 1, n) + get(I, P, 1, i) * P[n - 1];
        if(w == w1 || w == w2)
        {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}