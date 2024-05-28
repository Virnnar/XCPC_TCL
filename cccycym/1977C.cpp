#include <bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 2E3 + 10, mod = 1E9 + 7;

int clac(vector<pair<int, int>> &t, int d)
{
    int LCM = 0, cnt = 0;
    for(auto [x, y] : t)
        if(d % x == 0)
        {
            if(LCM == 0) LCM = x;
            else LCM = lcm(LCM, x);
            cnt += y;
        }
    if(LCM != d) cnt = 0;
    return cnt;
}

void run()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];

    LL LCM = 1;
    int mx = *max_element(a.begin(), a.end());
    for(int i = 0; i < n; i ++ )
    {
        LCM = lcm(LCM, a[i]);
        if(LCM > mx) 
        {
            cout << n << endl;
            return;
        }
    }

    int res = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i ++ ) mp[a[i]] ++;
    vector<pair<int, int>> t;
    for(auto it : mp) t.push_back(it);

    for(int i = 1; i * i <= mx; i ++ )
        if(mx % i == 0)
        {
            if(!mp.count(i)) res = max(res, clac(t, i));
            if(!mp.count(mx / i)) res = max(res, clac(t, mx / i));
        }

    cout << res << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- )
    {
        run();
    }
    return 0;
}