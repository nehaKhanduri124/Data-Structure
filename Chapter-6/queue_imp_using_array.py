class Que:
    element = []
    front = rear = -1

    def EnQueue(self, item):
        if self.rear == -1 and self.front == -1:
            self.rear = self.front = 0
            self.element.append(item)
        else:
            self.rear += 1
            self.element.append(item)

    def DeQueue(self):
        if self.front == -1 and self.rear == -1:
            print(" Underflow! ")
        else:
            print(f"Dequeue element : {self.element[self.front]}")
            self.front += 1

    def Peek(self):
        if self.front == -1 and self.rear == -1:
            print(" Underflow! ")
        else:
            print(f"Peek element is: {self.element[self.front]}")

    def Display(self):
        temp = self.front
        if self.front == -1 and self.rear == -1:
            print(" Underflow! ")
        else:
            while temp <= self.rear:
                print(self.element[temp], end=" ")
                temp = temp + 1
            print()


Q = Que()
print("Elements in the queue are :")
Q.EnQueue(89)
Q.EnQueue(23)
Q.EnQueue(35)
Q.EnQueue(76)
Q.EnQueue(10)
Q.Display()

Q.DeQueue()
Q.Display()
Q.Peek()
