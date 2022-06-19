def Heapify(a, i):
    size = len(a)
    small = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < size and a[small] > a[l]:
        small = l
    if r < size and a[small] > a[r]:
        small = r
    if small != i:
        a[i], a[small] = a[small], a[i]
        Heapify(a, small)


def Insert(a, key):
    size = len(a)
    if size == 0:
        a.append(key)
    else:
        a.append(key)
        for i in range(size - 1, -1, -1):
            Heapify(a, i)

def Delete(a,ele):
    print("After deleting "+str(ele)+" from heap")
    size = len(a)
    i=0
    flag = 0
    for i in range(0,size):
        if ele == a[i]:
            flag += 1
            break
    if flag == 0:
        print(ele+" is not present in the heap")
        return

    a[i], a[size-1] = a[size-1], a[i]
    a.remove(ele)
    for i in range(size - 1, -1, -1):
        Heapify(a, i)

def Display(a):
    print("Min Heap array is : " + str(a))
    print()

A = []
Insert(A, 7)
Insert(A, 6)
Insert(A, 2)
Insert(A, 1)
Insert(A, 4)
Insert(A, 36)
Insert(A, 50)
Display(A)
Delete(A, 1)
Display(A)