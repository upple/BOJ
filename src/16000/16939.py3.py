p=[0, 3, 1, 2, 4, 5]
cube = list(map(int, input().split()))

if cube[0:4]==[cube[0]]*4 and cube[8:12]==[cube[8]]*4:
    if cube[12:14]==cube[6:8]==[cube[12]]*2 and cube[4:6]==cube[18:20]==[cube[4]]*2 and cube[16:18]==cube[22:24]==[cube[16]]*2 and cube[20:22]==cube[14:16]==[cube[20]]*2:
        print(1)

    elif cube[12:14]==cube[22:24]==[cube[12]]*2 and cube[4:6]==cube[14:16]==[cube[4]]*2 and cube[16:18]==cube[6:8]==[cube[16]]*2 and cube[20:22]==cube[18:20]==[cube[20]]*2:
        print(1)

    else:
        print(0)

elif cube[4:8]==[cube[4]]*4 and cube[20:24]==[cube[20]]*4:
    if cube[0]==cube[1]==cube[13]==cube[15] and cube[12]==cube[14]==cube[8]==cube[9] and cube[10]==cube[11]==cube[18]==cube[16] and cube[19]==cube[17]==cube[2]==cube[3]:
        print(1)

    elif cube[0]==cube[1]==cube[16]==cube[18] and cube[12]==cube[14]==cube[2]==cube[3] and cube[10]==cube[11]==cube[13]==cube[15] and cube[19]==cube[17]==cube[8]==cube[9]:
        print(1)

    else:
        print(0)

elif cube[12:16]==[cube[12]]*4 and cube[16:20]==[cube[16]]*4:
    if cube[0]==cube[2]==cube[5]==cube[7] and cube[4]==cube[6]==cube[9]==cube[11] and cube[8]==cube[10]==cube[20]==cube[22] and cube[21]==cube[23]==cube[1]==cube[3]:
        print(1)

    elif cube[0]==cube[2]==cube[20]==cube[22] and cube[4]==cube[6]==cube[1]==cube[3] and cube[8]==cube[10]==cube[5]==cube[7] and cube[21]==cube[23]==cube[9]==cube[11]:
        print(1)

    else:
        print(0)

else: print(0)
