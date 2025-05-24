#include "Monday.h"

using namespace virmar;

int n, s, m;

void doit() {
    cin >> n >> s >> m;
    vector<pair<int, int> > a(n);
    for (auto &i: a)
        cin >> i.first >> i.second;
    // sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++)
        if (a[i + 1].first - a[i].second >= s) return puts("YES"), void();
    if (a[0].first >= s) return puts("YES"), void();
    if (m - a.back().second >= s) return puts("YES"), void();
    puts("NO");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}