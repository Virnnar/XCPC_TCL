#include "Monday.h"

using namespace virmar;

const int N = 1E5 + 10, mod = 1E9 + 7;

int n, A, B;
int a[N];

bool check(int x)
{
    int res = 0;

    for(int i = 1, j = 1, sum = 0; j <= n;)
    { 
        while(j <= n && sum < A) sum += a[j ++ ];
        while(i <= j && sum > B) sum -= a[i ++ ];
        if(sum >= A && sum <= B) 
        {
            i = j;
            res ++;
            sum = 0;
        }
    }

    return res >= x;
}

void doit()
{
    cin >> n >> A >> B;
        for(int i = 1; i <= n; i ++ ) cin >> a[i];

        int l = 0, r = n;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
}

int main()
{
    virmar::READ_ARC = false;
    int T = 1;
    cin >> T;
    while (T--)
        doit();
    return 0;
}