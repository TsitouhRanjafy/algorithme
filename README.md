# Palindrome Partitioning

Cette [algorithme](https://www.youtube.com/watch?v=aZ0B1eWkSVU) consiste à trouver le minimum nombre de coupes nécessaire pour partititionner une chaîne de caractère en **Palindrome**.

Une partitionnement d'une chaîne est **Palindrome Partitioning** si chaque sous-chaîne de la partition est palindrome.

[Palindrome.Partitioning.pdf](https://github.com/user-attachments/files/18151679/Diagramme.sans.nom.drawio.pdf)

![Palindrome.Partitioning](https://github.com/user-attachments/assets/aa0c95fc-e4c2-415a-b467-77d771d9dcbb)

### Exemple:

  - Input: s = 'aabhh'
  
  - Output: list = ['aa','b','hh] 


### Code with `Python`

```Python
from recursive import isPalindrome;


def palindromePartitioning(s):
    newList = [];
    existPalindrome = False;

    i = 0;
    n = len(s)
    while i<n:
        if (isPalindrome(s)): 
            newList.append(s);
            return newList;
        j = 1;
        existPalindrome = False;
        while j < (len(s)-1):
            if (isPalindrome(s[0:j+1])):
                newList.append(s[0:j+1]);
                s = s[j+1:];
                existPalindrome = True;
                break;
            j+=1;
        if (existPalindrome==False):
            newList.append(s[0]);
            s = s[1:];
        i+=1;
    return newList;

print(palindromePartitioning('aa'))
```

Bon conding!! 🎉



# Python Algorithms Collection

Explore a range of powerful algorithms implemented in Python 3.12.6. This repository includes efficient solutions for key algorithmic challenges, focusing on recursion, backtracking, and number theory.

## 📚 Algorithms Included

### 1. **Recursion & Backtracking**
- 🔗 [Recursive Functions](https://github.com/TsitouhRanjafy/Python/tree/recursive)  
  Dive into a series of recursive function implementations that solve common algorithmic problems through recursion.

- 🔗 [Prime Numbers](https://github.com/TsitouhRanjafy/Python/blob/base/base.py)  
  Efficient methods to identify prime numbers, leveraging number theory and recursion.

- 🔗 [Palindrome Partitioning](https://github.com/TsitouhRanjafy/Python/tree/palindrome.partitioning)  
  Solve the palindrome partitioning problem using backtracking techniques. Break a string into all possible palindromic partitions.

- 🔗 [Merge Array](https://github.com/TsitouhRanjafy/Python/blob/merge-array/merge-array.py) ([LeetCode 88](https://leetcode.com/problems/merge-sorted-array/submissions/1526158540))  
    Python solution for merging two sorted arrays in-place. The algorithm runs in `O(m + n)` time complexity and uses `O(1)` extra space.

- 🔗 [CheckParity01](https://github.com/TsitouhRanjafy/Python/blob/parity/parity.py)  
    - 1- Verification of parity 0 and 1 only **`isHasParity_0_1(list,i,q,contient1,contient0)`**
            


## 🚀 Features
- Written in Python 3.12.6
- Focus on core algorithms, recursion, and backtracking
- Clean, easy-to-understand code, optimized for performance







