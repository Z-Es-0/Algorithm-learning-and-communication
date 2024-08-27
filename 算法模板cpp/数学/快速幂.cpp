int mod_pow(int x, int y, int mod) { //取模mod
    long long res = 1;
    long long base = x;
    while (y > 0) {
        if (y & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        y >>= 1;
    }
    return res;
}