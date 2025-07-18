#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    string s; cin >> s;
    vector<int> cnt;
    int flag = 0, now = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') flag++, now = max(now, flag);
        if (s[i] == ')') flag--;
        if (flag == 0) cnt.push_back(now), now = 0;
    }
    if (cnt.size() == 1) return puts("NO"), void();
    puts("YES");
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