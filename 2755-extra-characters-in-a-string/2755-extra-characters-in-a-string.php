class Solution {
    function minExtraChar($s, $dictionary) {
        $maxVal = strlen($s) + 1;
        $dp = array_fill(0, strlen($s) + 1, $maxVal);
        $dp[0] = 0;

        $dictionarySet = array_flip($dictionary);

        for ($i = 1; $i <= strlen($s); ++$i) {
            $dp[$i] = $dp[$i - 1] + 1;
            for ($l = 1; $l <= $i; ++$l) {
                if (isset($dictionarySet[substr($s, $i - $l, $l)])) {
                    $dp[$i] = min($dp[$i], $dp[$i - $l]);
                }
            }
        }
        return $dp[strlen($s)];
    }
}