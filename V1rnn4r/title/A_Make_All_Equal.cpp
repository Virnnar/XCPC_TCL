#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    int now = a.front(), cnt = 0, ans = n;
    for (int i = 0; i < n; i++)
        if (a[i] != now) {ans = min(ans, n - cnt); now = a[i], cnt = 1;}
        else cnt++;
    cout << min(ans, n - cnt) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}