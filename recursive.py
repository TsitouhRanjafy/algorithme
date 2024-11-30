def factorielle(n):
    if n != 0:
        return (n*factorielle(n-1));
    else:
        return 1

def palindrome(n,i): 
    i = int(i);
    n = str(n);
    if i <= (len(n) // 2):
        if n[i] == n[len(n)-i-1]:
            return palindrome(n,i+1);
        else:
            return False;
    else:
        return True;
print(palindrome("rottar",0))
