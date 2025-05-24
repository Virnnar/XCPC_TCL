#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) d[i] = a[i] - a[i - 1];
    map<int, pair<int, int> > H;
    H[0] = {0, 0};
    for (int i = 0; i <= n; i++) H[d[i]].second = i;
    for (int i = n; i >= 0; i--) H[d[i]].first = i;
    
    int ans = H[0].second - H[0].first;
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
    cout << endl;
    for (auto [v, p]: H) {
        int i = p.first, j = p.second;
        cout << v << ' ' << i << ' ' << j << endl;
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    puts("--------------");

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}