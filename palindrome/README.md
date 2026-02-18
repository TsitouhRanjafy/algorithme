# Palindrome Partitioning

Cette [algorithme](https://www.youtube.com/watch?v=aZ0B1eWkSVU) consiste à trouver le minimum nombre de coupes nécessaire pour partititionner une chaîne de caractère en **Palindrome**.

Une partitionnement d'une chaîne est **Palindrome Partitioning** si chaque sous-chaîne de la partition est palindrome.

[Palindrome.Partitioning.pdf](https://github.com/user-attachments/files/18151679/Diagramme.sans.nom.drawio.pdf)

![Palindrome.Partitioning](https://github.com/user-attachments/assets/aa0c95fc-e4c2-415a-b467-77d771d9dcbb)

### Exemple:

  - Input: s = 'aabhh'
  
  - Output: list = ['aa','b','hh] 


### Code avec `Python`

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