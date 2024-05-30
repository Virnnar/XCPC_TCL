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
    int n, res = 0;
    cin >> n;
    vector<int> a(n), b;
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end());
    set<int> S;
    for(int i = 0; i < a.size(); i ++ )
        if(a[i] <= n && !S.count(a[i]))
            S.insert(a[i]);
        else b.push_back(a[i]);

    for(int i = 0, j = 1; i < b.size(); i ++, j ++ )
    {
        while(j <= n && S.count(j)) j ++;
        if(b[i] <= j * 2)
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