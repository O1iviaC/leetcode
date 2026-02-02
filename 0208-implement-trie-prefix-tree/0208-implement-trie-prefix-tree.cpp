/*
Build a tree like structure where the trie object is the root. 

Each Trie node contains an array of pointers, where each index corresponds to a letter of the alphabet and points to another Trie node representing that letter.

The boolean isEnd marks whether the path up to that node forms a complete word, which allows the Trie to distinguish between full words and prefixes of longer words.

At the start of each function create a temporary Trie called cur to navigate through the structure. A loop iterates through each character of the input string. If the pointer for a character is nullptr, a new Trie node is created. Otherwise, the existing node is reused. The traversal then moves cur to that child node.

Using this logic you can see if a string is in the trie or if its prefix is in the trie.

cur->child[i] = new Trie() creates linkages between letters or chars and cur = cur->child[i] is how we move along the linkages.

Note that each node doesn't actually store the value of the chars, the index of child itself represents a letter (index 0 is a, index 1 is b, index 2 is c, etc.)
*/
class Trie {
public:
    Trie* child[26];
    bool isEnd;

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26 ; i++){
            child[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie* cur = this;
        for(char c : word){
            int i = c - 'a';
            if(cur->child[i] == nullptr) cur->child[i] = new Trie();
            cur = cur->child[i];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for (char c : word){
            int i = c - 'a';
            if(cur->child[i] == nullptr) return false;
            cur = cur->child[i];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (char c: prefix){
            int i = c - 'a';
            if(cur->child[i] == nullptr) return false;
            cur = cur->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */