class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function minDeletions($s) {
        $result = 0;

        $frequency = array_count_values((array)str_split($s));
        rsort($frequency);

        for ($i = 0, $iMax = count($frequency); $i < $iMax - 1; $i++) {
            if ($frequency[$i] <= $frequency[$i+1]) {
                while (($frequency[$i+1] >= $frequency[$i]) && ($frequency[$i+1] !== 0)) {
                    $frequency[$i+1]--;
                    $result++;
                }
            }
        }
        return $result;
    }
}