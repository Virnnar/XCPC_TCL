#include "Monday.h"

using namespace virmar;

const int N = 3E5 + 6;

int n;
int a[N], b[N];

int handle(vector<int> a) {
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] <= a.size() - i - 1) return i + 1;
    return 0;
}

int solve(int a[]) {
    int pos = 1;
    while (pos <= n)
        if (a[pos] >= 0) break;
        else pos++;
    pos = min(pos, n);
    vector<int> t, p;
    for (int i = pos; i <= n; i++) t.push_back(a[i]);
    int res = handle(t);
    for (int i = pos + res - 1; i >= 1; i--) p.push_back(a[pos + res - 1] - a[i]);
    // for (auto i: p) cout << i << ' ';
    int res1 = handle(p);
    return max(res, res1);
}

void doit() {
    mset(a, 0);
    mset(b, 0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[n - i + 1] = -a[i];
    cout << max(solve(a), solve(b)) << endl;
    // cout << solve(a);

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}