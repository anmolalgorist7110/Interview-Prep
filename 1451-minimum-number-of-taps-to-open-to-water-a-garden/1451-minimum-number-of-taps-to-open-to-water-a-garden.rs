impl Solution {
    pub fn min_taps(n: i32, ranges: Vec<i32>) -> i32 {
        let mut arr = vec![0; (n + 1) as usize];
        
        for i in 0..ranges.len() {
            if ranges[i] == 0 { continue; }
            let left = std::cmp::max(0, i as i32 - ranges[i]) as usize;
            arr[left] = std::cmp::max(arr[left], (i as i32 + ranges[i]) as usize);
        }
        
        let (mut end, mut far_can_reach, mut cnt) = (0, 0, 0);
        for i in 0..=n as usize {
            if i > end {
                if far_can_reach <= end { return -1; }
                end = far_can_reach;
                cnt += 1;
            }
            far_can_reach = std::cmp::max(far_can_reach, arr[i]);
        }
        
        cnt + if end < n as usize { 1 } else { 0 }
    }
}