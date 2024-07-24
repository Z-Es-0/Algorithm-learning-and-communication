int bisect(const int* s, int size, int target) {
    auto it = upper_bound(s, s + size, target);
    if (it == s + size) {
        return -1;
    }
    return distance(s, it);
}