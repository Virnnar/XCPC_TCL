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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];

    for(int i = 1; i <= n; i ++ )
    {
        int l = 1, r = i;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(mid <= a[i - (mid - 1)]) l = mid;
            else r = mid - 1;
        }
        cout << l << ' ';
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}