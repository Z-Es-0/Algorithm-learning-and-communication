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



if __name__ == '__main__':#测试
    a=lest(Nodelst(1))#初始化链表a，首节点是值为1的节点
    g=Nodelst(9)#留一个节点对象
    a.append(g)
    for i in range(2,6):#循环添加节点
        a.append(Nodelst(i))

    a.insert(Nodelst(12),g)#插入
    i=0
    while i<a.long:
        print(a.find_index(i))#打印链表值
        i+=1


