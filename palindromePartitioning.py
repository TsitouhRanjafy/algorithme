import os,codecs
from recursive import partitioning,palindrome;


def palindromePartitioning(s):
    newList = [];
    newList.append(partitioning(s))
    i = 2;
    j = 0;
    while i<len(s):
        newPartition = partitioning(s,i);
        tmpList = [];
        while j<len(newPartition):
            print(palindrome(newPartition[j])," : "+newPartition[j]);
            if (palindrome(newPartition[j])): tmpList.append(newPartition[j]);
            j+=1;
        if len(tmpList)!=0: newList.append(tmpList)
        i+=1;
    return newList;

# print(palindromePartitioning('aabhh'))







