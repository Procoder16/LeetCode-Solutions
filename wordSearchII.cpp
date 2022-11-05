struct Node {
public:
	Node* child[26];
	bool end;
	string word;

	Node() {
		for(int i = 0;i < 26;i++)
			child[i] = NULL;
		end = false;
	}

	bool isEnd() {
		return end;
	}

	void setEnd(string w) {
		end = true;
		word = w;
	}

	void toggle() {
		end = false;
	}

	bool containsKey(char ch) {
		return (child[ch - 'a'] != NULL);
	}

	Node* createNode() {
		Node* newNode = new Node();
		return newNode;
	}

	string getWord() {
		return word;
	}
};

class Solution {
private:
	Node* root;

public:
	Solution() {
		root = new Node();
	}

	void insert(string &s) {
		Node* curr = root;

		for(auto ch : s) {
			if(!curr->containsKey(ch)) {
				curr->child[ch - 'a'] = curr->createNode();
			}
			curr = curr->child[ch - 'a'];
		}
		curr->setEnd(s);
	}

	void dfs(int i, int j, int m, int n, 
			 vector<vector<char>> &board, vector<string> &res, Node* root) {

		if(root->isEnd()) {
			res.push_back(root->getWord());
			root->toggle();
		}

		if(i < 0 || j < 0 || i == m || j == n || board[i][j] == '.')
			return;

		char curr = board[i][j];
		if(!root->containsKey(curr)) {
			return;
		}

		board[i][j] = '.';
		static int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

		for(int k = 0;k < 4;k++) {
			int nX = i + dir[k][0];
			int nY = j + dir[k][1];

			dfs(nX, nY, m, n, board, res, root->child[curr - 'a']);
		}
		board[i][j] = curr;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;

		for(auto word : words) {
			insert(word);
		}

		int m = board.size();
		int n = board[0].size();

		for(int i = 0;i < m;i++) {
			for(int j = 0;j < n;j++) {
				dfs(i, j, m, n, board, res, root);
			}
		}

		return res;
	}
};