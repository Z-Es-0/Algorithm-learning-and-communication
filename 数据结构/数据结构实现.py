#数据结构的实现
#抽象数据类型


class Stack:#栈
    def __init__(self, lst=None):#构造函数
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

    def find(self, x):
        
        root = x
        # 先找到根节点
        while self.parent[root] != root:
            root = self.parent[root]

        # 路径压缩，将路径上的所有节点直接指向根节点
        while self.parent[x] != root:
            next_node = self.parent[x]
            self.parent[x] = root
            x = next_node

        return root

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




#链表

class Nodelst:
    def __init__(self,value,next=None):
        self.value=value
        self.next=next
class lest:
    def __init__(self,begen,last=0):
        '''注意必须参数，began是Nodelst类型，last不用传参数'''
        self.begen=begen
        self.lst=[begen]
        self.last=last
        self.long=1
    def append(self,node):#向尾节点添加
        '''注意数据类型，node是节点类型，Nodelst类，无返回值'''
        self.lst.append(node)
        self.lst[self.last].next=len(self.lst) - 1
        self.last = len(self.lst) - 1
        self.long+=1

    def find_value(self,nodevalue):
        '''注意数据类型，nodevalue是任意类型，表示节点的值,返回索引值'''
        i=self.begen
        try:
            while i.value != nodevalue:
                p = i.next
                i = self.lst[p]
                if i.value == nodevalue:
                    return p
            return -1
        except:
            return -1
    def find_index(self,nodeindex):
        '''注意数据类型，nodeindex类型是int类型，
        返回节点值'''
        i=self.begen
        p=0
        try:
            while p <= nodeindex:
                if p == nodeindex:
                    return i.value
                i = self.lst[i.next]
                p += 1
                # print(p)
            return -1
        except:
            return -1

    def kill(self,precursor):#删除
        '''注意参数类型，precursor是Nodelst类型，是想要删除的节点前驱'''
        precursor.next=self.lst[precursor.next].next
        self.long-=1
    def insert(self,node,precursor):#插入
        self.lst.append(node)
        node.next=precursor.next
        precursor.next=len(self.lst)-1
        self.long+=1





