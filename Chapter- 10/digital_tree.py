class Trie_Node:

    def __init__(self):
        self.children = [None] * 26

        self.is_EndOfword = False


class Trie:

    def __init__(self):
        self.root = self.getNode()

    def getNode(self):

        return Trie_Node()

    def char_To_Index(self, ch):


        return ord(ch) - ord('a')

    def insert_key(self, key):


        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self.char_To_Index(key[level])


            if not pCrawl.children[index]:
                pCrawl.children[index] = self.getNode()
            pCrawl = pCrawl.children[index]

        pCrawl.is_EndOfword = True

    def search_key(self, key):


        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self.char_To_Index(key[level])
            if not pCrawl.children[index]:
                return False
            pCrawl = pCrawl.children[index]

        return pCrawl.is_EndOfword


def main():

    keys = ["hi", "this", "is", "heyy", "for",
            "bye"]
    output = ["Not present in trie", "Present in trie"]

    tr = Trie()

    for key in keys:
        tr.insert_key(key)

    print("{} ---- {}".format("hi", output[tr.search_key("hi")]))
    print("{} ---- {}".format("this", output[tr.search_key("this")]))
    print("{} ---- {}".format("is", output[tr.search_key("is")]))
    print("{} ---- {}".format("bye", output[tr.search_key("bye")]))


if __name__ == '__main__':
    main()
