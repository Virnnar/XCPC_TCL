#include "Monday.h"

using namespace virmar;

int n, m, k;

void doit() {
    cin >> n >> m >> k;
    vector<int> a;
    for (int i = n; i >= k; i--) a.push_back(i);
    for (int i = m + 1; i < k; i++) a.push_back(i);
    for (int i = 1; i <= m; i++) a.push_back(i);
    for (auto i: a) cout << i << ' ';
    cout << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}