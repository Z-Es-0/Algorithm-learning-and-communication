#四阶数独
#四阶数独;
#解法1：枚举序列
import random

# 初始化一个4x4的二维列表
matrix = [[0] * 4 for _ in range(4)]

# 对1到4进行随机排序并填入二维列表
for i in range(4):
    row = [1, 2, 3, 4]
    random.shuffle(row)  # 随机打乱列表
    matrix[i] = row  # 将打乱后的列表赋值给二维列表的一行

# 打印结果
for row in matrix:
    print(row) 