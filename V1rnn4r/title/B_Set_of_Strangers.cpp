#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m; cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    map<int, int> H;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            H[a[i][j]] = 1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i + 1 < n and a[i][j] == a[i + 1][j]) H[a[i][j]] = 2;
            if (j + 1 < m and a[i][j] == a[i][j + 1]) H[a[i][j]] = 2;
        }
    int x = accumulate(all(H), 0, [](auto acc, auto p) {
        return acc + p.second;
    }), y = max_element(all(H), [](auto a, auto b) {
        return a.second < b.second;
    }) -> second;

    cout << x - y << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}