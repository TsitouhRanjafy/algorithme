class Solution(object):
    def rotate(self, nums, k):
        k = k % len(nums)
        self.rotateIn(nums,k)

    def rotateIn(self,nums,k):
        n = len(nums)
        nums += nums
        nums[:] = nums[n-k:len(nums)-k]

nums = [-1,-100,3,99]

Solution().rotate(nums,2)
print(nums)