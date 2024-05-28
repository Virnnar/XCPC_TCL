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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<LL>  ans(n);

    for(int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        a[i] = {x, i};
    }

    sort(a.begin(), a.end());

    LL dis = 0;
    for(int i = 0; i < n; i ++ ) dis += a[i].first - a[0].first;
    ans[a[0].second] = dis;

    for(int i = 1; i < n; i ++ ) 
    {
        LL dx = a[i].first - a[i - 1].first;
        dis += max(0, i - 1) * dx;
        dis -= max(0, n - (i + 1)) * dx;
        ans[a[i].second] = dis;
    }

    for(int i = 0; i < n; i ++ ) cout << ans[i] + n << ' ';
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}