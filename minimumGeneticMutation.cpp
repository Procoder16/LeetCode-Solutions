class Solution {
public:
    struct Trie {
        bool isWord;
        Trie *next[4];
        Trie() {
            isWord = false;
            for(int i=0; i<4; i++) {
                next[i] = nullptr;
            }
        }
    } *root;
    
    int position(char c) {
        if(c == 'A') return 0;
        if(c == 'C') return 1;
        if(c == 'G') return 2;
        return 3;
    }
    
    void insert(string s) {
        Trie *cur = root;
        for(char c: s) {
            int pos = position(c);
            if(cur->next[pos] == nullptr)
                cur->next[pos] = new Trie();
            cur = cur->next[pos];
        }
        cur->isWord = true;
    }
    
    bool find(string s) {
        Trie *cur = root;
        for(char c: s) {
            int pos = position(c);
            if(cur->next[pos] == nullptr)
                return false;
            cur = cur->next[pos];
        }
        bool b = cur->isWord;
        cur->isWord = false;
        return b;
    }
    
    void pushQueue(queue<string> &q, string cur, char c, int pos) {
        string temp = cur;
        if(cur[pos] != c) {
            temp[pos] = c;
            if(find(temp)) {
                q.push(temp);
            }
        }
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        root = new Trie();
        for(string s: bank) {
            insert(s);
        }
        queue<string> q;
        int level = 0;
        q.push(start);
        string v = "ACGT";
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                string cur = q.front();
                if(cur == end) return level;
                q.pop();
                for(int j=0; j<8; j++) {
                    for(int k=0; k<4; k++) {
                        pushQueue(q, cur, v[k], j);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};