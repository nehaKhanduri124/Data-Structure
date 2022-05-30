class Stack:
    value = []
    head=-1

    def __init__(self):
        self.value = []
        self.head = -1

    def push(self,element):
        self.head = self.head +1
        self.value.append(element)

    def pop(self):
        if(self.head==-1):
            print(" stack underflow")
        else:
            self.value.pop();
            self.head = self.head - 1
            print("Last value has been popped from the stack")

    def topElement(self):
        if (self.head == -1):
            print("Stack is empty")
        else:
            print(self.value[len(self.value) - 1])

    def printStack(self):
        if (self.head == -1):
            print("Stack is empty")
        else:
            for i in self.value:
                print(i,end=" ")


s = Stack();
s.push(3)
s.push(1)
s.push(7)
s.push(15)
s.push(65)
s.printStack()
print()

s.pop()
s.printStack()
print()

print("peeking element is: ",end=" ")
s.topElement()
