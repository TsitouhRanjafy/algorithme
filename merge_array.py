class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i = m - 1
        j = n - 1
        k = m + n - 1

        # Cas où les deux listes sont vides, rien à fusionner
        if (len(nums1) == 0) and (len(nums2) == 0): return

        # Cas où nums1 est vide, on copie directement nums2 dans nums1
        if len(nums1) == 0:
            nums1[:] = nums2
        while k >= 0:
            if j >= 0: # Vérifie s'il reste encore des éléments à traiter dans nums2
                if (i >=0 ) and (nums1[i] >= nums2[j]):
                    nums1[k] = nums1[i]
                    i -= 1
                else:
                    nums1[k] = nums2[j]
                    j -= 1
            else:
                break
            k -= 1

list1 = [3,4,6,0,0]
n1 = 3

Solution().merge(list1,n1,[1,2],2)
print(f"{list1}")