class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (matrix==nullptr || rows<1 || cols<1 || str==nullptr)
            return false;
        bool* visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);
        int pathLen = 0;
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (hasPathCore(matrix,rows, cols,i,j,str,pathLen,visited))
                    return true;
            }
        }
        delete[] visited;
        return false;
    }
    bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLen, bool* visited){
        if (str[pathLen] == '\0') return true;
        
        bool hasPath = false;
        if (row>=0 && row<rows && col>=0 && col<cols && 
            matrix[row*cols+col]==str[pathLen] && !visited[row*cols+col]){
            pathLen++;
            visited[row*cols+col] = true;
            hasPath = hasPathCore(matrix,rows,cols,row,col-1,str,pathLen,visited) ||
                hasPathCore(matrix,rows,cols,row,col+1,str,pathLen,visited) ||
                hasPathCore(matrix,rows,cols,row+1,col,str,pathLen,visited) ||
                hasPathCore(matrix,rows,cols,row-1,col,str,pathLen,visited);
            
            if (!hasPath){//否则，状态还原
                pathLen--;
                visited[row*cols+col] = false;
            }
        }
        return hasPath;
    }

};
