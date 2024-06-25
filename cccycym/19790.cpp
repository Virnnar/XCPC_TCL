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
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int maxi = max(a[0], a[1]);
    for(int i = 0; i < n - 1; i ++ )
        maxi = min(maxi, max(a[i], a[i + 1]));

    cout << maxi - 1 << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}