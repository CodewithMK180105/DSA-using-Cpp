// 📘 1804. Implement Trie II (Prefix Tree)
// A trie (or prefix tree) is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.

// Implement the Trie class:

// Trie()
// Initializes the trie object.

// void insert(String word)
// Inserts the string word into the trie.

// int countWordsEqualTo(String word)
// Returns the number of instances of the string word in the trie.

// int countWordsStartingWith(String prefix)
// Returns the number of strings in the trie that have prefix as a prefix.

// void erase(String word)
// Erases one occurrence of the string word from the trie.

#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public: 
        char data;
        bool terminal;
        unordered_map<char, Node*> childrens;
        int charCount;
        int wordsEndingHere;

        Node(char data){
            this->data=data;
            this->terminal=false;
            this->charCount=1;
            this->wordsEndingHere=0;
        }
};

class Trie{
public:
    Node* root;
    Trie(){
        root=new Node('\0');
    }

    void insert(string word){
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(curr->childrens.count(ch)){
                curr=curr->childrens[ch];
                curr->charCount++;
            } else{
                Node* newNode=new Node(ch);
                curr->childrens[ch]=newNode;
                curr=newNode;
            }
        }
        curr->terminal=true;
        curr->wordsEndingHere++;
    }

    int countWordsEqualTo(string word){
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(curr->childrens.count(ch)){
                curr=curr->childrens[ch];
            } else return 0;
        }
        if(curr->terminal) return curr->wordsEndingHere;
        return 0;
    }

    int countWordsStartingWith(string prefix){
        Node* curr=root;
        int len=0;
        int i;
        for(i=0;i<prefix.size();i++){
            char ch=prefix[i];
            if(curr->childrens.count(ch)){
                curr=curr->childrens[ch];
            } else break;
        }
        return i==prefix.size()? curr->charCount: 0;
    }

    void erase(string word) {
        Node* curr = root;
        for (char ch : word) {
            Node* nextNode = curr->childrens[ch];

            if (nextNode->charCount == 1) {
                curr->childrens.erase(ch); // Remove entire subtree
                return;
            }

            nextNode->charCount--;
            curr = nextNode;
        }
        curr->wordsEndingHere--;
        if (curr->wordsEndingHere == 0) {
            curr->terminal = false;
        }
    }

};
int main() {
    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apex");
    trie.insert("bat");
    trie.insert("batman");
    trie.insert("bat");

    cout << "--- Counts Before Erase ---" << endl;

    cout << "Count of 'apple': " << trie.countWordsEqualTo("apple") << endl; // 2
    cout << "Count of 'app': " << trie.countWordsEqualTo("app") << endl;     // 1
    cout << "Count of 'bat': " << trie.countWordsEqualTo("bat") << endl;     // 2
    cout << "Count of 'batman': " << trie.countWordsEqualTo("batman") << endl; // 1
    cout << "Count of 'apex': " << trie.countWordsEqualTo("apex") << endl;   // 1
    cout << "Count of 'cat': " << trie.countWordsEqualTo("cat") << endl;     // 0

    cout << "Words starting with 'ap': " << trie.countWordsStartingWith("ap") << endl; // 4
    cout << "Words starting with 'bat': " << trie.countWordsStartingWith("bat") << endl; // 3
    cout << "Words starting with 'b': " << trie.countWordsStartingWith("b") << endl;     // 3
    cout << "Words starting with 'c': " << trie.countWordsStartingWith("c") << endl;     // 0

    // Erase some words
    trie.erase("apple"); // Remove one "apple"
    trie.erase("bat");   // Remove one "bat"

    cout << "\n--- Counts After Erase ---" << endl;

    cout << "Count of 'apple': " << trie.countWordsEqualTo("apple") << endl; // 1
    cout << "Count of 'bat': " << trie.countWordsEqualTo("bat") << endl;     // 1
    cout << "Words starting with 'ap': " << trie.countWordsStartingWith("ap") << endl; // 4
    cout << "Words starting with 'bat': " << trie.countWordsStartingWith("bat") << endl; // 2

    // Erase remaining
    trie.erase("apple");
    trie.erase("app");
    trie.erase("apex");
    trie.erase("bat");
    trie.erase("batman");

    cout << "\n--- Counts After All Erased ---" << endl;

    cout << "Count of 'apple': " << trie.countWordsEqualTo("apple") << endl; // 0
    cout << "Count of 'app': " << trie.countWordsEqualTo("app") << endl;     // 0
    cout << "Count of 'apex': " << trie.countWordsEqualTo("apex") << endl;   // 0
    cout << "Count of 'bat': " << trie.countWordsEqualTo("bat") << endl;     // 0
    cout << "Count of 'batman': " << trie.countWordsEqualTo("batman") << endl; // 0
    cout << "Words starting with 'ap': " << trie.countWordsStartingWith("ap") << endl; // 0
    cout << "Words starting with 'bat': " << trie.countWordsStartingWith("bat") << endl; // 0

    return 0;
}
