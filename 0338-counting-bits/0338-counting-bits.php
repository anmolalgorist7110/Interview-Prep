class Solution {
    function countBits($n) {
        $res = [];
        for($i=0; $i<=$n; $i++) {
            $result[] = substr_count(decbin($i), "1");
        }
        return $result;
    }
}