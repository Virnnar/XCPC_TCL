#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<int> d(n);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    int L = 0, R = 0;
    vector<int> lt;
    for (int i = 0; i < n; i++) {
        if (d[i] == -1)
            lt.push_back(i);
        else
            L += d[i];

        while (L < l[i]) {
            if (lt.empty()) return puts("-1"), void();
            d[lt.back()] = 1;
            L++;
            lt.pop_back();
        }

        while (L + lt.size() > r[i]) {
            if (lt.empty()) return puts("-1"), void();
            d[lt.back()] = 0;
            lt.pop_back();
        }
    }

    for (auto i : d) cout << max(0, i) << ' ';
    puts("");
}

int main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}



void init() {

}