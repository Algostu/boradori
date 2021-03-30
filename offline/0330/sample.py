import random

testset = [ random.randrange(1000000) for _ in range(1) ]
for test_size in testset:
    print(test_size)
    item = [ str(random.randrange(-1000000000, 1000000000)) for _ in range(test_size) ]
    print(" ".join(item))