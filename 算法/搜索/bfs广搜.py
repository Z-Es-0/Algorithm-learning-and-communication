from queue import Queue

def pand(w, i):
    a = w[0] + i[0]
    b = w[1] + i[1]
    return (a, b)

def check(xy, n, m):
    if 0 <= xy[0] < n and 0 <= xy[1] < m:
        return True
    return False

def bfs(ans, q, n, m, pan):
    op = 0
    while not q.empty():
        op += 1
        size = q.qsize()  # 获取当前层的节点数
        for _ in range(size):
            w = q.get()
            for i in pan:
                r = pand(w, i)
                if check(r, n, m) and ans[r[0]][r[1]] == 0 and r!=(0,0):
                    q.put(r)
                    ans[r[0]][r[1]] = op

if __name__ == '__main__':
    q = Queue()
    n, m, x, y = map(int, input().split())
    x, y = x - 1, y - 1
    q.put((x, y))
    ans = [[0 for _ in range(m)] for _ in range(n)]
    pan = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    bfs(ans, q, n, m, pan)
    for i in ans:
        print(" ".join(map(str, i)))