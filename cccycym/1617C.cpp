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
    vector<int> a(n), st(n + 1);
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i ++ ) 
        if(a[i] < i + 1)
        {
            cout << -1 << endl;
            return;
        }

    int res = 0;
    for(int i = 0, j = 1; i < n; i ++, j ++ )
    {
        if(a[i] == j) continue;
        if(a[i] < j * 2) 
        {
            cout << -1 << endl;
            return;
        }
        res ++;
    }
    cout << res << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}