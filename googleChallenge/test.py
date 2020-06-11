def func(a, l):
    print("l: " + str(l))
    print(len(l))
    l.append(a)
    print("l again: " + str(l))

func(1, [])
