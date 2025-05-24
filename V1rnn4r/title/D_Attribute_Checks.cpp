#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m, pf = 0; cin >> n >> m;
    vector<int> f(m + 1, -INF), d(m + 20, 0);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        int r = read<int>();
        if (r == 0) {
            int sum = 0;
            for (int i = 0; i < d.size(); i++) {
                sum += d[i];
                d[i] = 0;
                if (i < f.size()) f[i] += sum;
            }
            for (int i = m; i > 0; i--) f[i] = max(f[i], f[i - 1]);
            pf++;
        } else if (r > 0) d[r] ++, d[m + 1] --;
        else d[0]++, d[max(r + pf + 1, 0)]--;
    }
    int sum = 0;
    for (int i = 0; i < d.size(); i++) {
        sum += d[i];
        d[i] = 0;
        if (i < f.size()) f[i] += sum;
    }
    cout << *max_element(f.begin(), f.end()) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}