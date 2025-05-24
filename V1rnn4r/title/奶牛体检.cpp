#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), ans(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += a[i] == b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++) {
            int sum = cnt;
            for (int l = i, r = i + j; 1 <= l and r <= n; l--, r++) {
                if (a[l] == b[l]) sum--;
                if (a[r] == b[r]) sum--;
                if (a[l] == b[r]) sum++;
                if (a[r] == b[l]) sum++;
                ans[sum]++;
            }
        }
    for (int i = 0; i <= n; i++)
        cout << ans[i] << endl;

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}