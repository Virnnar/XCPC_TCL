#include "Monday.h"

using namespace virmar;

inline bool get(ll t, int i) {return t >> i & 1;}



int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}