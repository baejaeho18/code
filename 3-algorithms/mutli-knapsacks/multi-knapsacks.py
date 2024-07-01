## 현대오토에버 코테(24.06.29) 2번 문제
## 담을 수 있는 용량이 k인 m개의 가방이 있다.
## 무게와 가치가 제각각인 상품이 n개 있다.
## m, k, n과 무게와 가치를 담은 2*n 배열이 주어진다.
## 담아갈 수 있는 최대 가치를 구하라

# 3, 7, 7, [[1,1],[2,100],[3,100],[4,50],[5,50],[6,50],[7,50]]

# 가방수, 용량, 상품 수, 무게와 가치
def optimize(m, k, n, purchases):
    weights = [purchases[0] for purchases in purchases]
    values = [purchases[1] for purchases in purchases]

    dp = [[[0] * (k + 1) for _ in range(m + 1)] for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            for l in range(k + 1):
                # 안 넣을 떄
                dp[i][j][l] = dp[i-1][j][l]
                # 넣을 떄
                if l >= weights[i-1]:
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l-weights[i-1]] + values[i-1])
                if j > 1 and l >= weights[i-1]:
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][k-weights[i-1]] + values[i-1])
    return dp[n][m][k]

m = 2
k = 7
n = 7
purchases = [[1,1],[2,100],[3,100],[4,50],[5,50],[6,50],[7,50]]

print(optimize(m, k, n, purchases))
# 2 : 301
# 3 : 351