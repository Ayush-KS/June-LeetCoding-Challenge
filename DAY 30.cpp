// Word Search II

class trieNode {
    public:
    
    trieNode** children;
    bool isTerminal;
    
    trieNode() {
        isTerminal = false;
        children = new trieNode*[26];
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    
    trieNode* getChild(char c) {
        return children[c - 'a'];
    }
    
    void setChild(char c, trieNode* child) {
        children[c - 'a'] = child;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    public:
    trieNode* root;
    
    Trie() {
        root = new trieNode();    
    }
    
    void insertList(vector<string>& words) {
        for(string word : words) {
            insert(word);
        }
    }
    

    void insert(string word) {
        trieNode* temp = root;
        for(int i = 0; i < word.size(); i++) {
            trieNode* child = temp -> getChild(word[i]);
            if(!child) {
                child = new trieNode();
                temp -> setChild(word[i], child);
            }
            temp = child;
        }
        temp -> isTerminal = true;
    }
};

class Solution {
public:
    int dx[4] = {1, -1,0, 0};
    int dy[4] = {0, 0, 1, -1};
    
     void dfs(vector<vector<char>>& board, int x, int y, vector<string>& words, vector<string>& output, trieNode* root, string curr) {
        if(!root)
            return;
         
        if(root -> isTerminal) {
            output.push_back(curr);
            root -> isTerminal = false;
        }
         
        if(x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || board[x][y] == '#')
            return;
   
        if(root -> isTerminal) {
            output.push_back(curr);
            root -> isTerminal = false;
        }
        char c = board[x][y];
        curr += board[x][y];
        board[x][y] = '#';
       
        for(int i = 0; i < 4; i++) {
            dfs(board, x + dx[i], y + dy[i], words, output, root -> children[c - 'a'], curr);
        }
        board[x][y] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* myTrie = new Trie();
        myTrie -> insertList(words);
        trieNode* root = myTrie -> root;
        vector<string> output;
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                dfs(board, i, j, words, output, root, "");
            }
        }
        return output;
    }
};