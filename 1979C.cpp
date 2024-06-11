#include <bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1E5 + 10, mod = 1E9 + 7;

bool check(vector<LL> &a, vector<LL> &b, LL x, LL ma)
{
    int n = a.size();
    for(int i = 0; i < n; i ++ )
        b[i] = x * ma / a[i];
    LL sum = 0;
    for(int i = 0; i < n; i ++ ) sum += b[i];
    for(int i = 0; i < n; i ++ )
        if(a[i] * b[i] <= sum) 
            return false;
    return true;
}

void run()
{
    int n;
    cin >> n;
    vector<LL> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];

    LL maxi = *max_element(a.begin(), a.end());

    LL l = 1, r = 1E9;
    while(l < r)
    {
        LL mid = l + r >> 1;
        if(check(a, b, mid, maxi)) r = mid;
        else l = mid + 1;
    }

    if(check(a, b, l, maxi)) 
    {
        for(int i = 0; i < n; i ++ ) cout << b[i] << ' ';
        cout << endl;
    }
    else cout << -1 << endl;
    
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}