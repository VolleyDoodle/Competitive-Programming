n = int(input())
p_i = input().split()
count = 0
count1 = 0
t_i = input().split()
st_index = 0
end_index = n - 1
for k in range(n):
    t_i[k] = int(t_i[k])
    p_i[k] = int(p_i[k])
#bruteforce, solve by sides first 
while (True):

    count = 0
    for t in range(n):
        if t_i[t] == p_i[t]:
            count+=1
    if count == n:
        break
    if int(p_i[st_index]) == int(t_i[st_index]):
        #solved
        st_index = st_index + 1
    if int(p_i[end_index]) == int(t_i[end_index]):
        end_index = end_index - 1
    #good above
    
    if int(t_i[st_index]) > int(p_i[st_index]):
        count1 +=1
        for x in range(st_index, end_index + 1):
            if int(t_i[x]) < int(p_i[x]):
                break
            else:
                t_i[x] = int(t_i[x]) - 1

    elif int(t_i[st_index]) < int(p_i[st_index]):
        count1 +=1
        for z in range(st_index, end_index + 1):
            if int(t_i[z]) > int(p_i[z]):
                break
            else:
                t_i[z] = int(t_i[z]) + 1
print(count1)    
