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







