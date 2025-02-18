
def isHasParity_0_1(list,i,q,contient1,contient0):
    print(f"---> q{q} ---", end="")
    if len(list) <= 3:
        return False

    if (q == 0) and (i == len(list) and contient0 and contient1 ):
        return True
    elif i <= (len(list) - 1):
        if list[i] == 0:
            return isHasParity_0_1(list, i + 1, (q + 2) % 4,contient1,True)
        elif (q == 1) or (q == 3):
            return isHasParity_0_1(list, i + 1, (q + 4) % 5,True,contient0)
        else:
            return isHasParity_0_1(list,i + 1, (q + 5) % 4,True,contient0)
    else:
        return False

print(f"\n {isHasParity_0_1([0,0,1,0,0,1],0,0,0,0)}") # true

# [0,0,0,1] False, [1,0,1,0] True, [0,0] False