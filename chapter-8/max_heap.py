def Heapify(arr1, i):
    size = len(arr1)
    larg = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < size and arr1[larg] < arr1[l]:
        larg = l
    if r < size and arr1[larg] < arr1[r]:
        larg = r
    if larg != i:
        arr1[i], arr1[larg] = arr1[larg], arr1[i]
        Heapify(arr1, larg)


def Insert(arr1, key):
    size = len(arr1)
    if size == 0:
        arr1.append(key)
    else:
        arr1.append(key)
        for i in range(size - 1, -1, -1):
            Heapify(arr1, i)

def Delete(arr1,value):
    print("after deleting : "+str(value))
    size = len(arr1)
    i=0
    for i in range(0,size):
        if value == arr1[i]:
            break

    arr1[i], arr1[size-1] = arr1[size-1], arr1[i]
    arr1.remove(value)
    for i in range(size - 1, -1, -1):
        Heapify(arr1, i)

def display(arr1):
    print(" Max Heap : " + str(arr1))
    print()


arr2 = []

Insert(arr2,56)
Insert(arr2, 3)
Insert(arr2, 12)
Insert(arr2, 52)
Insert(arr2, 16)
Insert(arr2, 90)
Insert(arr2,100)
Insert(arr2,101)

display(arr2)
Delete(arr2,12)
display(arr2)