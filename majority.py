class Solution:
    def majorityElement(self, nums):
        repetition = majority = 0

        i = 0
        while i < len(nums):
            if repetition == 0:
                majority = nums[i]

            if nums[i] == majority:
                repetition += 1
            else:
                repetition -= 1
                
            if repetition == 0:
                majority = nums[i]

            i += 1
        return majority


list = [2,1,3,1,3]

print(Solution().majorityElement(list))