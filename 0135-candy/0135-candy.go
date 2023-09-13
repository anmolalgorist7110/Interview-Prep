func candy(ratings []int) int {
    l := len(ratings)
    res := 0
    candies := make([]int, l)
   

    // Give one candy for each child
    for i :=0 ; i < l; i ++ {
        candies[i] = 1
    }

    // Check left -> right
    for i := 1; i < l; i ++ {
        if ratings[i] > ratings[i-1] {
            candies[i] = candies[i-1] + 1
        }
    }

    // Check right -> left
    for i := l - 2; i >= 0 ; i -- {
        if ratings[i] > ratings[i+1] && candies[i] <= candies[i+1] {
            candies[i] = candies[i+1] + 1
        }
    }

    for i := 0; i < l; i ++ {
        res += candies[i]
    }




    return res
}