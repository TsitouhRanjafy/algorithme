# Factorielle 
def factorielle(n):
    if n != 0:
        return (n*factorielle(n-1));
    else:
        return 1
# print(factorielle(3)); ==> 6

# Palindrome <string><int>
# <string>: le mot à tester
# <int>: élever n caractère au début et à la fin du mot avant de tester
def isPalindrome(n,i=0): 
    n = n.lower();
    if i <= (len(n) // 2):
        if n[i] == n[len(n)-i-1]:
            return isPalindrome(n,i+1);
        else:
            return False;
    else:
        return True;
# print(isPalindrome("ici"))  ==> True
