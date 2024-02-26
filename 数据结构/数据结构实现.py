#数据结构的实现
class Stack:#栈
    def __init__(self, lst=None):
        if lst is None:
            lst = []
        self.lst = lst
        self.update_long()

    def push(self, i):#入栈，参数为入栈的元素
        self.lst.append(i)
        self.update_long()

    def pop(self, i=-1):#出栈
        if not self.is_empty():
            removed_item = self.lst.pop(i)
            self.update_long()
            return removed_item
        else:
            raise IndexError("Stack is empty, cannot pop.")

    def howlong(self):
        return self.long

    def is_empty(self):
        return len(self.lst) == 0

    def update_long(self):
        self.long = len(self.lst)



#查并集
class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n+5)]#多开点数组

    def find(self, x):#查询函数
        if self.parent[x] != x:#路径压缩
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):#合并函数
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            self.parent[rootX] = rootY


class Queue:
    def __init__(self, capacity=10000):
        self.items = [None] * capacity  # 初始化一个固定容量的数组
        self.left = 0  # 队列头部的指针
        self.right = 0  # 队列尾部的指针，也是下一个元素插入的位置
        self.size = 0  # 队列当前的大小
        self.capacity = capacity  # 队列的容量

    def enqueue(self, item):
        if self.size == self.capacity:
            print("队列已满")
            return False
        self.items[self.right] = item
        self.right = (self.right + 1) % self.capacity  # 环形队列处理
        self.size += 1
        return True

    def dequeue(self):
        if self.size == 0:
            print("队列为空")
            return None
        item = self.items[self.left]
        self.items[self.left] = None  # 可选：清除引用，帮助垃圾收集
        self.left = (self.left + 1) % self.capacity  # 环形队列处理
        self.size -= 1
        return item

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity

    def get_size(self):
        return self.size
    

#二叉树，节点类
class Node:#节点
    def __init__(self,a,b):
        self.left=a
        self.right=b
