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
    int x, p;
    cin >> x;
    vector<int> op(1, x);

    for(int i = 0; ; i ++ )
        if(x >> i & 1)
        {
            if(x == 1 << i)
            {
                p = i;
                break;
            }
            x -= 1 << i;
            op.push_back(x);
        }

    while(p)
    {
        x -= 1 << p - 1;
        op.push_back(x);
        p --;
    }

    cout << op.size() << endl;
    for(auto i : op) cout << i << ' ';
    cout << endl;
}


int main()
{
    int T;
    cin >> T;
    while(T -- ) run();
    return 0;
}