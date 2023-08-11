#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode *root, string word)
{
    // base case
    // jab word ka size 0 ho jayega tab end wala letter ko terminal mark karna hei
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // node is present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}

bool search(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        return false;
    }

    // recursion
    return search(child, word.substr(1));
}

void deleteWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = false;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        return;
    }

    // rec call
    deleteWord(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('-');

    // root->insertWord("coding");
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");
    insertWord(root, "shona");
    deleteWord(root, "coder");
    if (search(root, "coder"))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Not present" << endl;
    }

    return 0;
}