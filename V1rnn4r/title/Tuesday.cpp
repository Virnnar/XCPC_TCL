void fun(int m) {
    if (m == 0) {
        for (int i = n; i >= 1; i--)
            cout << a[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= 9; i++) {
        a[m] = i;
        fun(m - 1);
    }
}