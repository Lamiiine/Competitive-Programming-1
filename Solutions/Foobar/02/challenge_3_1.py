def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a * (b / gcd(a, b))

class rational:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def normalize(self):
        d = gcd(self.x, self.y)
        self.x /= d
        self.y /= d
    def __repr__(self):
        return str(self.x) + "/" + str(self.y)
    def add(self, other):
        ans = rational(self.x * other.y + other.x * self.y, self.y * other.y)
        ans.normalize()
        return ans
    def mul(self, other):
        ans = rational(self.x * other.x, self.y * other.y)
        ans.normalize()
        return ans
    def sub(self, other):
        return self.add(rational(-other.x, other.y))
    def div(self, other):
        return self.mul(rational(other.y, other.x))

def solve(matrix):
    n = len(matrix)
    for c in range(0, n):
        for i in range(c + 1, n):
            factor = matrix[i][c].div(matrix[c][c])
            for k in range(n, c - 1, -1):
                matrix[i][k] = matrix[i][k].sub(matrix[c][k].mul(factor))
    ans = [rational(0, 1) for i in range(n)]
    for j in range(n - 1, -1, -1):
        t = rational(0, 1)
        for k in range(j + 1, n):
            t = t.add(matrix[j][k].mul(ans[k]))
        ans[j] = matrix[j][n].sub(t).div(matrix[j][j])
    return ans

def answer(m):
    dimension = len(m)
    rowSum = [sum(m[i]) for i in range(dimension)]
    ans = []
    for i in range(dimension):
        if rowSum[i] == 0:
            #i is a terminal state, for which we need to find an answer!
            matrix = []
            for j in range(dimension):
                if rowSum[j] == 0:
                    matrix.append([rational(1 if j == k else 0, 1) for k in range(dimension)])
                    matrix[j].append(rational(1 if i == j else 0, 1))
                else:
                    matrix.append([rational(m[j][k] - (rowSum[j] if j == k else 0), rowSum[j]) for k in range(dimension)])
                    matrix[j].append(rational(0, 1))
            ans.append(solve(matrix)[0])
    denominator = 1
    for r in ans:
        denominator = lcm(denominator, r.y)
    intAns = []
    for r in ans:
        intAns.append(r.x * denominator / r.y)
    intAns.append(denominator)
    return intAns

