bool isPalindrome(int num) {
    std::string str = std::to_string(num);
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

std::vector<int> getPalindromes(int N) {
    std::vector<int> palindromes;
    for (int i = 1; i <= N; ++i) {
        if (isPalindrome(i)) {
            palindromes.push_back(i);
        }
    }
    return palindromes;
}