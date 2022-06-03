class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class Binary_search_tree:
    def Create_Tree(self, root, temp):
        new_node = Node(temp)
        new_node.left = None
        new_node.right = None
        return new_node

    def Insert_Tree(self, root, temp):
        if root == None:
            return self.Create_Tree(root, temp)
        elif root.value > temp:
            root.left = self.Insert_Tree(root.left, temp)
        else:
            root.right = self.Insert_Tree(root.right, temp)
        return root

    def successor(self, root):
        root = root.right
        while root.left != None:
            root = root.left
        return root

    def predessor(self, root):
        root = root.left
        while (root.right != None):
            root = root.right
        return root

    def Delete_Tree(self, root, data):
        if root is None:
            return root
        if root.value > data:
            root.left = self.Delete_Tree(root.left, data)
        elif root.value < data:
            root.right = self.Delete_Tree(root.right, data)
        else:
            if root.left is None and root.right is None:
                return None
            elif root.left is not None:
                pre = self.predessor(root)
                root.value = pre.value
                root.left = self.Delete_Tree(root.left, root.value)
            else:
                pre = self.successor(root)
                root.value = pre.value
                root.right = self.Delete_Tree(root.right, root.value)
        return root

    def searching(self, root, temp):
        if root is None:
            return None
        if root.value == temp:
            return root
        elif root.value > temp:
            return self.searching(root.left, temp)
        else:
            return self.searching(root.right, temp)

    def Print(self, root):
        if root is None:
            return
        self.Print(root.left)
        print(root.value, end=" ")
        self.Print(root.right)


root = None
tree = Binary_search_tree()
root = tree.Insert_Tree(root, 39)
root = tree.Insert_Tree(root, 29)
root = tree.Insert_Tree(root, 1)
root = tree.Insert_Tree(root, 87)
root = tree.Insert_Tree(root, 63)
tree.Print(root)
print()

print("after deletion ")
root = tree.Delete_Tree(root, 63)
tree.Print(root)
print()

print("after searching 39")
n = tree.searching(root, 1)
if (n != None):
    print(f"{n.value} Found")
else:
    print("not present in the tree")
