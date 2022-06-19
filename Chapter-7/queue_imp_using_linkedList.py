class Node1:
    def __init__(self, item):
        self.item = item
        self.link = None


class Que:
    def __init__(self):
        self.front = 0
        self.rear = 0

    def EnQueue(self, key):
        newNode = Node1(key)
        newNode.link = None
        if self.front == 0 and self.rear == 0:
            self.front = self.rear = newNode
        else:
            self.rear.link = newNode
            self.rear = newNode

    def DeQueue(self):
        if self.front == 0 and self.rear == 0:
            print(" Underflow!! ")
        elif self.front == self.rear:
            print(f"Dequeue element : {self.front.item}")
            self.front = self.rear = 0

        else:
            print(f"Dequeue element : {self.front.item}")
            self.front = self.front.link

    def Peek_Que(self):
        if self.front == 0 and self.rear == 0:
            print(" Underflow!! ")
        else:
            print(f"Peek element is: {self.front.item}")

    def Display_Que(self):
        temp = self.front
        if self.front == 0 and self.rear == 0:
            print(" Underflow!! ")
        else:
            print("ElementS in the queue are : ", end=" ")
            while temp is not None:
                print(temp.item, end=" ")
                temp = temp.link
            print()


Q = Que()
Q.EnQueue(1)
Q.EnQueue(90)
Q.EnQueue(87)
Q.EnQueue(23)
Q.EnQueue(56)
Q.EnQueue(32)
Q.EnQueue(34)
Q.Display_Que()
Q.DeQueue()
Q.Display_Que()
Q.Peek_Que()
