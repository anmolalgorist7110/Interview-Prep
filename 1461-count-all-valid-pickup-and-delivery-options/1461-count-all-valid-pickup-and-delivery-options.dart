class Solution {
  int countOrders(int n) {
List<int> dp = List.generate(n, (_) => 0);
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    int totalPoint = 2 * (i + 1);
    int numberOfCase = totalPoint * (totalPoint - 1) ~/ 2;
    dp[i] = numberOfCase * dp[i - 1] % 1000000007;
  }

  return dp[n - 1];
  }
}