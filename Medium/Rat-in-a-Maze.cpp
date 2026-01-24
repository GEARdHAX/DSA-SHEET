#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMove(int x, int y,
                 vector<vector<int>> &visited,
                 vector<vector<int>> &maze,
                 int n)
    {
        return (x >= 0 && x < n &&
                y >= 0 && y < n &&
                visited[x][y] == 0 &&
                maze[x][y] == 1);
    }

    void solve(vector<vector<int>> &maze,
               vector<string> &ans,
               vector<vector<int>> &visited,
               int x, int y,
               string path,
               int n)
    {
        // destination reached
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Left
        if (canMove(x, y - 1, visited, maze, n))
        {
            solve(maze, ans, visited, x, y - 1, path + 'L', n);
        }

        // Right
        if (canMove(x, y + 1, visited, maze, n))
        {
            solve(maze, ans, visited, x, y + 1, path + 'R', n);
        }

        // Up
        if (canMove(x - 1, y, visited, maze, n))
        {
            solve(maze, ans, visited, x - 1, y, path + 'U', n);
        }

        // Down
        if (canMove(x + 1, y, visited, maze, n))
        {
            solve(maze, ans, visited, x + 1, y, path + 'D', n);
        }

        visited[x][y] = 0; // backtrack
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0)
            return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(maze, ans, visited, 0, 0, "", n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
