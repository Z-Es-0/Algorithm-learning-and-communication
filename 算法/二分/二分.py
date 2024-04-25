def binary_search(arr, target):
    l = 0  # 左边界
    r = len(arr) - 1  # 右边界
    while l <= r:
        mid = l + (r - l) // 2  # 中间位置
        #print(f"Left: {l}, Right: {r}, Middle: {mid}, Middle Value: {arr[mid]}")  # 打印当前的左、右边界和中间值
        if arr[mid] == target:
            return mid  # 找到目标，返回索引
        elif arr[mid] < target:
            l = mid + 1  # 调整左边界
        else:
            r = mid - 1  # 调整右边界
    return -1  # 未找到目标，返回-1
#介绍一个库：bisect
'''在python文件前直接加
import bisect
就可以直接用bisect.bisect()函数进行二分查找
但是二分答案还得自己手搓'''



