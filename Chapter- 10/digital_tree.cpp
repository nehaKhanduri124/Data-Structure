#include <bits/stdc++.h>
using namespace std;

const int AlphabetSize = 26;
struct trie_Node
{
	struct trie_Node *children[AlphabetSize];

	bool isEndOfWord;
};

struct trie_Node *getNode(void)
{
	struct trie_Node *pNode = new trie_Node;

	pNode->isEndOfWord = false;

	for (int i = 0; i < AlphabetSize; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(struct trie_Node *root, string key)
{
	struct trie_Node *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
}

bool search(struct trie_Node *root, string key)
{
	struct trie_Node *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}

int main()
{
	string keys[] = {"hi", "this", "that",
					"happy", "any", "but",
					"bye", "new" };
	int num = sizeof(keys)/sizeof(keys[0]);

	struct trie_Node *root = getNode();

	for (int i = 0; i < num; i++)
		insert(root, keys[i]);

	search(root, "hi")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "this")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "that")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "happy")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "think")? cout << "Yes\n" :
						cout << "No\n";
	return 0;
}
