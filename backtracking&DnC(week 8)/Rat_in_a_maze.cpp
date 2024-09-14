#include <bits/stdc++.h>
using namespace std;

// a function that will handle the below mentioned possibilities
// possibility hai
//->path closed
// out of bound
// check is pos is already visited
bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col,
            vector<vector<bool>> &visited)
{
    if ((newx >= 0 && newx < row) &&
        (newy >= 0 && newy < col) &&
        maze[newx][newy] == 1 && visited[newx][newy] == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void PrintAllPaths(int maze[][4], int row, int col, int srcx, int srcy,
                   string &output, vector<vector<bool>> &visited)
{
    // base case
    // destinations coordinates are row-1,col-1
    if (srcx == row - 1 && srcy == col - 1)
    {
        // reached destination
        cout << output << endl;
        return;
    }
    // 1 case mai solve kar lunga baaki recursion sambhal lega

    // UP
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('U');
        PrintAllPaths(maze, row, col, newx, newy, output, visited);
        // backtracking (mark unvisited when go back)
        output.pop_back();
        visited[newx][newy] = false;
    }

    // Right
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('R');
        PrintAllPaths(maze, row, col, newx, newy, output, visited);
        // backtracking (mark unvisited when go back)
        output.pop_back();
        visited[newx][newy] = false;
    }
    // Down
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('D');
        PrintAllPaths(maze, row, col, newx, newy, output, visited);
        // backtracking (mark unvisited when go back)
        output.pop_back();
        visited[newx][newy] = false;
    }
    // Left
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('L');
        PrintAllPaths(maze, row, col, newx, newy, output, visited);
        // backtracking (mark unvisited when go back)
        output.pop_back();
        visited[newx][newy] = false;
    }
}
int main()
{
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if (maze[0][0] == 0)
    {
        // src position is closed that means Rat cannot move
        cout << "No path Exists" << endl;
        return 0;
    }
    else
    {
        visited[srcx][srcy] = true;
        PrintAllPaths(maze, row, col, srcx, srcy, output, visited);
    }
    return 0;
}