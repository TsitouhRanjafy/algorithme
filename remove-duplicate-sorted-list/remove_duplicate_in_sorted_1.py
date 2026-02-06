class Solution(object):
    def removeDuplicates(self, nums):
        k = 0
        i = 1
        while i < len(nums):
            if nums[i] > nums[k]:
                nums[k+1] = nums[i]
                k += 1
            i += 1
        return k + 1