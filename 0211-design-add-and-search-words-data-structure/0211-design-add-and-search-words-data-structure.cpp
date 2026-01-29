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