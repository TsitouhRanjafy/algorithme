# Factorielle 
def factorielle(n):
    if n != 0:
        return (n*factorielle(n-1));
    else:
        return 1
# print(factorielle(3)); ==> 6

# Palindrome 
def palindrome(n,i=0): 
    n = n.lower();
    if i <= (len(n) // 2):
        if n[i] == n[len(n)-i-1]:
            return palindrome(n,i+1);
        else:
            return False;
    else:
        return True;
# print(palindrome("ici")) ==> True

