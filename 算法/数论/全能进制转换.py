f=['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
def cse(n, base):
    global f
    if n == 0:
        return "0"

    result = ""
    while n != 0:
        r = n % base

        n //= base

        if r < 0:
            r += abs(base)
            n += 1

        result = f[r] + result

    return result


if __name__ == "__main__":
    n,b=map(int,input().split())#输入的n为10进制数字，b为进制基数
    result = cse(n, b)
    print(f"{n}={result}(base{b})")