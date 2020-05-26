from itertools import combinations

def solution(n):
    n = int(n)
    sum = 0
    cnt = 0
    answer = 0
    while sum<n:
        pos = n-sum
        sum = sum + pow(2,cnt)
        cnt = cnt+1

    cnt = cnt - 1

    if pos == 1:
        answer = pow(3,cnt)
    else:
        answer = pow(3,cnt)
        pos = pos - 1
        literal_list = [a for a in(range(cnt))]
        comb_list = []
        for i in range(cnt):
            temp = combinations(literal_list,i+1)
            for j in list(temp):
                temp_sum = 0
                for k in j:
                    temp_sum=temp_sum+pow(3,k)
                comb_list.append(temp_sum)
        print(comb_list)
        comb_list.sort()
        print(comb_list)
        print(f'pos is = {pos}')
        for idx, i in enumerate(comb_list):
            if idx == pos-1:
                answer = answer + i

    print(f'Answer is {answer}')
    return answer

solution(11)