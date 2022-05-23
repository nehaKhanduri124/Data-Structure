class Node:
    def __init__(self, value):
        self.value = value
        self.next_val = None

class Linked_List:
    def __init__(self):
        self.head_val = None

    def add(self, new_value):
        new_node = Node(new_value)
        new_node.next_val = self.head_val
        self.head_val = new_node

    def delete_Node(self,key):
        temp = self.head_val
        if(temp is not None):
            if(temp.value == key):
                self.head_val = temp.next_val
                temp = None
                return
        while(temp is not None):

            if(temp.value == key):
                break
            prev = temp
            temp = temp.next_val
        if(temp == None):
            return
        prev.next_val = temp.next_val
        temp = None

    def list_print(self):
        print_val = self.head_val
        while(print_val):
            print(f"{print_val.value}  ")
            print_val = print_val.next_val


list = Linked_List()

list.add(1)
list.add(2)
list.add(3)
list.add(4)
list.add(5)
print("Linked list created")
list.list_print()
list.delete_Node(4);
print("After deletion element 4")
list.list_print()
