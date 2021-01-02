num_input = 10000
with open("input.txt", "w") as f:
    f.write(str(num_input)+'\n')
    for value in range(num_input):
        f.write("%d %d\n" % (value, value+1))
