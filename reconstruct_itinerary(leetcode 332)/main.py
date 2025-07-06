init = "JFK"

tickets2 = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"],["JFK","BDF"]]

tickets3 = [["JFK","ATL"],["ATL","JFK"]]

tickets4 = [["JFK","SFO"],["JFK","ATL"],["SFO","JFK"],["ATL","AAA"],["AAA","ATL"],["ATL","BBB"],["BBB","ATL"],["ATL","CCC"],["CCC","ATL"],["ATL","DDD"],["DDD","ATL"],["ATL","EEE"]]

tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
def findItinerary(tickets):
    JFK_index = 0
    newTikects = []
    j = 0


    for i in range(len(tickets)):

        if (tickets[i][0] == init):
            if JFK_index == 0:
                newTikects.insert(JFK_index,tickets[i][0])
                j += 1
                if (j - 1) >= 2:
                    if newTikects[JFK_index + 1] != tickets[i][1]:
                        newTikects[JFK_index + 1] = tickets[i][1]
                        j += 1
                else:
                    newTikects.insert(j,tickets[i][1])
                    j += 1
                JFK_index += 2
            else:
                k = 1
                while k < JFK_index:
                    print(f"{newTikects[k]} > {tickets[i][1]}: {(newTikects[k] > tickets[i][1])}")
                    if (newTikects[k] > tickets[i][1]):     
                        newTikects.insert(k - 1,tickets[i][0])
                        newTikects.insert(k,tickets[i][1])
                        j += 2
                        JFK_index += 2
                        break
                    if k == JFK_index - 1:
                        newTikects.insert(k + 1,tickets[i][0])
                        j += 1
                        if len(newTikects) > (k + 2):
                            if newTikects[k + 2] != tickets[i][1]:
                                newTikects.insert(k + 2,tickets[i][1])
                                j += 1
                        else:
                            newTikects.insert(k + 2,tickets[i][1])
                            j += 1
                        JFK_index += 2
                        break
                    k += 2
        else:
            if tickets[i][1] != init:
                if tickets[i][0] in newTikects[JFK_index - 1: -1]:
                    current_index = newTikects[JFK_index - 1: -1].index(tickets[i][0]) + JFK_index - 1
                    if (j - 1) >= (current_index + 1):
                        if newTikects[current_index + 1] != tickets[i][1]:
                            newTikects.insert(current_index + 1,tickets[i][1])
                            j += 1
                    else:
                        newTikects.insert(current_index + 1, tickets[i][1])
                        j += 1
                        print(f"ici: {newTikects}")
                else:
                    if j >= 1:
                        if newTikects[j - 1] != tickets[i][0]:
                            newTikects.insert(j,tickets[i][0])
                            j += 1
                    else:
                        newTikects.insert(j,tickets[i][0])
                        j += 1
                    newTikects.insert(j ,tickets[i][1])
                    j += 1
            else:
                if tickets[i][0] not in newTikects[0:JFK_index - 1]:
                    if newTikects[JFK_index - 1] == tickets[i][0]:
                        newTikects.insert(JFK_index,tickets[i][1])
        print(f"{i}:{newTikects}")
    return newTikects
                
print(findItinerary(tickets4))
# print(findItinerary(tickets))
# print(findItinerary(tickets3))
# ["JFK","ATL","JFK","SFO","ATL","SFO"]


# list = [1,2,3,4,5,6,7,8,9]

# print(list[3:-1])
# print(6 in list[3:-1])

# print(list[3:-1].index(6))

# print(list[3:-1].index(6) + 3)