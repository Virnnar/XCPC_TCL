#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> ans;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        ans.push_back(s.find('#'));
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] + 1 << ' ';
    cout << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}