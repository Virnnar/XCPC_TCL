#include "Monday.h"

using namespace virmar;

void doit() {
    string s[100];
    int n = 6;
    for (int i = 1; i <= 6; i++) cin >> s[i];
    for (int i = 1; i <= n; i++)
        cout << s[i] << endl;
    puts("");
    sort(s + 1, s + 7);
    for (int i = 1; i <= n; i++)
        cout << s[i] << endl;
    puts("");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //  cin >> T;
    while (T--) doit();
    return 0;
}