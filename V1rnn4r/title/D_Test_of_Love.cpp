#include "Monday.h"

using namespace virmar;

int n, m, k;
string s;

void doit() {
    cin >> n >> m >> k >> s;
    s = '_' + s;
    vector<int> idx;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == 'L') idx.push_back(i);
    idx.push_back(n);
    for (auto i: idx) cout << i << ' ';
    cout << endl;j
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}