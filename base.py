import cmath
# Un boolean à chaque index pour indiquer s'il premier ou pas
def listPremierByIndex(n):
    n += 1;
    list = [True] * n;
    list[0] = False;
    list[1] = False;

    i = 2;
    k = 1;
    while (i <= int(cmath.sqrt(n).real)):
        if list[i] == False: continue;
        k = i*i;
        while k <= n:
            list[k]=False;
            k *= 2;
        i += 1;
    return list;

print(listPremierByIndex(10))
