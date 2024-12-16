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
def palindrome(n,i=0): 
    n = n.lower();
    if i <= (len(n) // 2):
        if n[i] == n[len(n)-i-1]:
            return palindrome(n,i+1);
        else:
            return False;
    else:
        return True;
# print(palindrome("ici"))  ==> True


# Partitition <string><int>
# <string>: le mot à décomposer
# <int>: décomposer par n
def partitioning(string,n=1):
    newList = [];
    i = 0;
    j = 0;
    tmp = 0;
    while (i < ((len(string)//n) + (len(string)%n)) ):
        tmp = j+n;
        k = '';
        while ( (j<tmp) and (j<len(string)) ):
            k+=string[j];
            j+=1;
        if (k!=''): newList.append(k);
        i+=1;
    return newList;
# print(partitioning('abv',2)); ==> ['ab','v']

