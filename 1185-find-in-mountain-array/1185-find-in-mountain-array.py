class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        length = mountain_arr.length()

        # Find the index of the peak element in the mountain array.
        peak_index = self.find_peak_index(1, length - 2, mountain_arr)

        # Binary search for the target in the increasing part of the mountain array.
        increasing_index = self.binary_search(0, peak_index, target, mountain_arr, False)
        if mountain_arr.get(increasing_index) == target:
            return increasing_index  # Target found in the increasing part.

        # Binary search for the target in the decreasing part of the mountain array.
        decreasing_index = self.binary_search(peak_index + 1, length - 1, target, mountain_arr, True)
        if mountain_arr.get(decreasing_index) == target:
            return decreasing_index  # Target found in the decreasing part.

        return -1  # Target not found in the mountain array.

    def find_peak_index(self, low, high, mountainArr):
        while low != high:
            mid = low + (high - low) // 2
            if mountainArr.get(mid) < mountainArr.get(mid + 1):
                low = mid + 1  # Move to the right side (increasing slope).
            else:
                high = mid  # Move to the left side (decreasing slope).
        return low  # Return the index of the peak element.

    def binary_search(self, low, high, target, mountainArr, reversed):
        while low != high:
            mid = low + (high - low) // 2
            if reversed:
                if mountainArr.get(mid) > target:
                    low = mid + 1  # Move to the right side for a decreasing slope.
                else:
                    high = mid  # Move to the left side for an increasing slope.
            else:
                if mountainArr.get(mid) < target:
                    low = mid + 1  # Move to the right side for an increasing slope.
                else:
                    high = mid  # Move to the left side for a decreasing slope.
        return low  # Return the index where the target should be or would be inserted.