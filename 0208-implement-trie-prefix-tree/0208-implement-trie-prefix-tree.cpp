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