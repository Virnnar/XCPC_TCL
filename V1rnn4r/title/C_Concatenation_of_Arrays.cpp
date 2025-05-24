#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<pair<int, int> > a(n);
    for (auto &i: a)
        cin >> i.first >> i.second;
    sort(a.begin(), a.end(), [](pair<int, int> p, pair<int, int> q) {
        if (max(p.first, p.second) == max(q.first, q.second)) return min(p.first, p.second) < min(q.first, q.second);
        return max(p.first, p.second) < max(q.first, q.second);
    });

    for (auto [u, v]: a)
        cout << u << ' ' << v << ' ';
    puts("");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}