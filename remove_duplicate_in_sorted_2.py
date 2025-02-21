from impacket.ese import FLAGS_PARENT


class Solution(object):
    def removeDuplicates(self, nums):
        k = 0
        i = 1
        max_atteint = False
        while i < len(nums):
            if (nums[k] == nums[i]) and (max_atteint == False):
                nums[k + 1] = nums[i]
                k += 1
                i += 1
                max_atteint = True
            elif nums[k] < nums[i]:
                nums[k + 1] = nums[i]
                k += 1
                i += 1
                max_atteint = False
            else:
                i += 1
        return k + 1

lists = [0,0,1]

print(Solution().removeDuplicates(lists))

print(lists)