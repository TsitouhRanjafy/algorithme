text = 'abracadabradabfdzefjdabjdazdbdafezfdabfdkzejfb'
pattern = 'dab'

def count_occurence(text, pattern):
    compteur, i = 0, 0
    while True:
        occurence = search(text, pattern, i)
        if occurence == -1:
            return compteur
        else: 
            compteur += 1
            i = occurence + 1

def correspondance(text, pattern, p, i):
    for j in range(p - 1, -1, -1):
        x = text[i + j]
        if x != pattern[j]:
            decalage = max(1, j - right(x))
            return(False, decalage)
    return (True, 0)

def search(text, pattern, start):
    n = len(text)
    p = len(pattern)
    calculeinRight(pattern, p)
    i = start
    while i + p <= n:
        ok, decalage = correspondance(text, pattern, p, i)
        if ok:
            return i
        else:
            i = i + decalage
    return -1

def calculeinRight(pattern, p):
    global inRight
    inRight = {}
    for j in range(p):
        inRight[pattern[j]] = j

def right(c):
    global inRight
    if c in inRight.keys():
        return inRight[c]
    else:
        return -1
    

print(count_occurence(text, pattern))