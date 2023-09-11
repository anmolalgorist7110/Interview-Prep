class Solution {

    /**
     * @param Integer[] $groupSizes
     * @return Integer[][]
     */
    function groupThePeople($groupSizes) {
        $groups = [];
        foreach ($groupSizes as $key => $val) {
            $groups[$val][] = $key;
        }

        $data = [];
        foreach ($groups as $size => $group) {
            if ($size < count($group)) {
                $data = array_merge($data, array_chunk($group, $size));
            } else {
                $data[] = $group;
            }
        }

        asort($data);
        return $data;
    }
}