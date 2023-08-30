# @param {Integer[]} nums
# @return {Integer}
def minimum_replacement(nums)
    result = 0
    n = nums.size

    (n - 2).downto(0) do |i|
        curr = nums[i]
        _next = nums[i+1]

        if curr > _next
            higher_bound = (curr / _next.to_f).ceil
            result += higher_bound - 1
            nums[i] = (curr / higher_bound).floor
        end
    end

    result
end