import string
def comp_dict(q, item):
    return all([q[alpha] <= item[alpha] for alpha in list(string.ascii_lowercase)])

def get_abc_count(in_str):
    alphabet = {alpha : 0 for alpha in list(string.ascii_lowercase)}
    for ch in in_str:
        alphabet[ch] += 1
    return alphabet

N = int(input())
db = [input() for _ in range(N)]
db_alpha = [get_abc_count(st) for st in db]
Q = int(input())
query = [input() for _ in range(Q)]
query_alpha = [get_abc_count(st) for st in query]
for i in range(len(query)):
    cnt = 0
    for j in range(len(db)):
        if comp_dict(query_alpha[i], db_alpha[j]):
            if query[i] in db[j]:
                cnt+=1
    print(cnt)
