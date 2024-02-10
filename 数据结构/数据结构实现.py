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