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
    for(int& i : a) cin >> i;

    int mx = *max_element(a.begin(), a.end());
    if(mx < 0) 
    {
        cout << mx << endl;
        return ;
    }

    LL ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i ++ )
    {
        if(i & 1) ans1 += max(a[i], 0);
        else ans2 += max(a[i], 0);
    }
    cout << max(ans1, ans2) << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}