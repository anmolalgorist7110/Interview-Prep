impl Solution {
    pub fn maximal_network_rank(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let mut connections = vec![vec![false; n as usize]; n as usize];
        let mut city_rank = vec![0; n as usize];
        
        for road in &roads {
            let (city_a, city_b) = (road[0] as usize, road[1] as usize);
            connections[city_a][city_b] = true;
            connections[city_b][city_a] = true;
            city_rank[city_a] += 1;
            city_rank[city_b] += 1;
        }
        
        let mut max_rank = 0;
        for i in 0..n as usize {
            for j in (i + 1)..n as usize {
                let rank = city_rank[i] + city_rank[j] - if connections[i][j] { 1 } else { 0 };
                max_rank = max_rank.max(rank);
            }
        }
        
        max_rank
    }
}