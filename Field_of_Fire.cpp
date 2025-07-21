#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n, t; cin >> n >> t;
    string s; cin >> s;

    vector<int> vis(2 * n + 1);
    
    for (int i = 0; i < n; i++)
        if (s[i] == '1') {
            vis[max(i - t, 0)]++;
            vis[min(i + t + 1, 2 * n)]--;
            vis[max(i + n - t, 0)]++;
            vis[min(i + n + t + 1, 2 * n)]--;
        }
    
    for (int i = 1; i <= 2 * n; i++) vis[i] += vis[i - 1];
    
    int ans = 0;
    for (int i = 0; i < n; i++) ans += vis[i] == 0 and vis[i + n] == 0;


    int maxl = 0;
    for (int i = 0, c = 0; i < 2 * n; i++) {
        if (s[i % n] == '1') c = 0;
        else c++;
        maxl = max(maxl, c);
    }

    cout << ans + max(max(0, maxl - t - 1) - max(0, maxl - 2 * t), 0) << endl;


}

signed main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T --> 0) doit();
    return 0;
}

void init() {

}