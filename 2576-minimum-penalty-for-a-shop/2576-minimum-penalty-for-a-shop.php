class Solution {

    /**
     * @param String $customers
     * @return Integer
     */
    function bestClosingTime($customers) {
         $customers_arr = str_split($customers);
        $count_y = 0;
        $result = 0;
        
        for($i=0;$i<count($customers_arr);$i++){
            if($customers_arr[$i] == 'Y'){
                $count_y++;
            }
        }
        
        $min_y = $count_y;
        
        for($j=0;$j<count($customers_arr);$j++){
            if($customers_arr[$j] == "Y"){
                $count_y--;
            }
            else{
                $count_y++;
            }
            
            if($min_y > $count_y){
                $result = $j + 1;
                $min_y = $count_y;
            }
        }
        return $result;
    }
}