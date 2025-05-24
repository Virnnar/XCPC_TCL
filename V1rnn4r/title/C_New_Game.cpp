#include "Monday.h"

using namespace virmar;

void doit() {
    int n, k; cin >> n >> k;
    map<int, int> H;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        H[t]++;
    }
    vector<pair<int, int> > a;
    for (auto i: H) a.push_back(i);
    // for (auto i: H) cout << i.second << ' ';
    // cout << endl;
    int i = 0, j = 0, sum = a[0].second, ans = 0;
    n = a.size();
    while (i < n) {
        if (i > j) {
            j = i, sum = a[j].second;
        }
        while (j + 1 < n and j - i + 1 < k and a[j + 1].first == a[j].first + 1) sum += a[++j].second;
        ans = max(ans, sum);
        sum -= a[i++].second;
    }
    cout << ans << endl;

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}