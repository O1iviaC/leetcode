/*
Similar to the implementation of Implement Trie (Prefix Tree), set up an array of pointers.
Every index of the array of pointers represents a lower case letter of the alphabet and whenever a word is added, a WordDictionary() object is created at an array index corresponding to each letter of the word. If an index is nullptr that means the letter isn't used to spell the word. If an index's WordDictionary objet has that isEnd is true, that means from the first letter to that one, there is a valid word. 

The only difference is now is how we treat the '.'
Every time a '.' is encountered, recursively go through a DFS and search through each letter(index) to see where/if there is non-null WordDictionary object, if there is then there is a valid letter path from the '.' from which an existing word continues to spell out and then continue checking the rest of the letters of the word.

*/
class WordDictionary {
public:
    WordDictionary* words[26];
    bool isEnd;

    WordDictionary() {
        isEnd = false;
        for (int i = 0; i < 26; i++) words[i] = nullptr;
    }

    void addWord(string word) {
        WordDictionary* cur = this;
        for (char c : word) {
            int i = c - 'a';
            if (cur->words[i] == nullptr) cur->words[i] = new WordDictionary();
            cur = cur->words[i];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, this);
    }

    bool dfs(const string& word, int pos, WordDictionary* node) {
        if (pos == (int)word.size()) return node->isEnd;

        char c = word[pos];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->words[i] != nullptr && dfs(word, pos + 1, node->words[i]))
                    return true;
            }
            return false;
        } else {
            int i = c - 'a';
            if (node->words[i] == nullptr) return false;
            return dfs(word, pos + 1, node->words[i]);
        }
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */