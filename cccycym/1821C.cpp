#include <bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1E9
#define eps 1E-6
#define icc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1E5 + 10, mod = 1E9 + 7;

string s;

int solve(char c)
{
    int res = 0;
    for(int i = 0; i < s.size(); i ++ )
    {
        while(i < s.size() && s[i] == c) i ++;
        int j = i;
        while(j < s.size() && s[j] != c) j ++;
        if(j > i) res = max(res, (int)(log(j - i) / log(2) + eps) + 1);
        i = j;
    }
    return res;
}

void run()
{
    cin >> s;
    vector<int> cnt(26);
    for(int i = 0; i < s.size(); i ++ ) cnt[s[i] - 'a'] ++;
    int ans = INF;
    for(int i = 0; i < 26; i ++ )
        if(cnt[i])
            ans = min(ans, solve('a' + i));
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}