/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* quadTree(int row, int col, int n, vector<vector<int>> &grid){
        if(n == 0) return NULL;
        bool isLeaf = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i + row][j + col] != grid[row][col]){
                    isLeaf = false;
                    break;
                }
                if(isLeaf == false) break;
            }
        }

        if(isLeaf){
            return new Node(grid[row][col], true);
        }

        Node* topLeft = quadTree(row, col, n / 2, grid);
        Node* topRight = quadTree(row, col + n / 2, n / 2, grid);
        Node* bottomLeft = quadTree(row + n / 2, col, n / 2, grid);
        Node* bottomRight = quadTree(row + n / 2, col + n / 2, n / 2, grid);

        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);

    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return quadTree(0, 0, n, grid);
    }
};