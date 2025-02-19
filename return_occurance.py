def removeElement(nums, val):
    k = 0
    i = 0
    while i < len(nums):
        if nums[i] != val:
            nums[k] = nums[i]
            k += 1
        i += 1
    return k

List = [0,3,0,2,4]

print(removeElement(List,0)) # 3
print(List) # [3, 2, 4, 2, 4]