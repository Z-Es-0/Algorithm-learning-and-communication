def fin(a, n):
    '''找到一个数组的区间和小于n的最长子段的长度'''
    left = 0
    #初始化两个指针left和right，分别表示滑动窗口的左右边界，都从数组的起始位置开始。
    sum = 0
    max_len = 0
    #初始化变量sum来记录窗口内元素的和，以及max_len来记录满足条件的最长子段的长度。
    for right in range(len(a)):
        sum += a[right]#移动right指针扩大窗口，每次移动后，更新sum。
        while sum >= n:#当sum大于等于n时，开始移动left指针缩小窗口，直到sum小于n
            sum -= a[left]
            left += 1
        max_len = max(max_len, right - left + 1)  # 每次在移动left指针后，如果sum小于n，更新max_len。
    return max_len
