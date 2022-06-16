class Node:
    def __init__(self, value):
        self.value = value
        self.link = None


class Stack_List:
    def __init__(self):
        self.head = 0

    def push_stack(self, key):
        newNode = Node(key)
        newNode.link = self.head
        self.head = newNode

    def pop_stack(self):
        temp = self.head
        if self.head == 0:
            print(" Stack Underflow! ")
        else:
            print(f"Popped element is: {self.head.value}")
            self.head = self.head.link
            del temp

    def peek_stack(self):
        if self.head == 0:
            print(" Stack Underflow! ")
        else:
            print(f"Peek element is: {self.head.value} ")

    def display(self):
        if self.head == 0:
            print(" Stack Underflow! ")
        else:
            print("Elements in the stack are : ")
            temp = self.head
            while temp != 0:
                print(temp.value)
                temp = temp.link


stack = Stack_List()
stack.push_stack(98)
stack.push_stack(56)
stack.push_stack(1)
stack.push_stack(34)
stack.push_stack(20)
stack.display()

stack.pop_stack()
stack.display()

stack.peek_stack()
