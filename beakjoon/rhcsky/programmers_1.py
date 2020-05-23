def solution(p):
    p = int(p)
    p = p+1
    while p:
        number = [0,0,0,0,0,0,0,0,0,0]
        temp = p
        while temp:
            if number[int(temp%10)] != 0:
                p = p + 1
                break
            number[int(temp%10)] = 1
            temp = int(temp/10)
        if temp == 0:
            answer = p
            break

    return answer


a = input()
print(solution(a))