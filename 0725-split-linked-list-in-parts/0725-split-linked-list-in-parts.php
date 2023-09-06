/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {

    /**
     * @param ListNode $head
     * @param Integer $k
     * @return ListNode[]
     */
    function splitListToParts($head, $k) {
        $data = array_fill(0, $k, []);

        if (!$head) {
            return $data;
        }

        $current = $head;
        $count = 0;

        while ($current) {
            $current = $current->next;
            $count++;
        }

        $current = $head;
        $val = $count / $k;
        $part = $count % $k;

        for ($i = 0; $i < $k; $i++) {
            $node = new ListNode();
            $tmp = $node;
            $max = $val + ($i < $part) - 1;

            for ($j = 0; $j <= $max; $j++) {
                $tmp->next = new ListNode($current->val);
                $tmp = $tmp->next;
                $current = $current->next;
            }

            $data[$i] = $node->next;
        }

        return $data;
    }
}