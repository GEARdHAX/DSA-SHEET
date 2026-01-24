#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMove(int x, int y, vector<vector<int>> &visited, vector<vector<int>> &maze, int n)
    {
        // This checks :-
        // Is Rat Inside the maze
        // Does Rat already visisted that square before ?
        // Is maze free from blockage
        if (x >= 0 && x <= n && y >= 0 && y <= n && visited[x][y] == 0 && maze[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void solve(vector<vector<int>> &maze, vector<string> &ans, vector<vector<int>> &visited, int x, int y, string path, int n)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;
        int newx, newy;
        // Left Step Condition :-
        newx = x - 1;
        newy = y;
        if (canMove(newx, newy, visited, maze, n))
        {
            path.push_back('L');
            solve(maze, ans, visited, newx, newy, path, n);
            path.pop_back();
        }
        // Right Step Condition :-
        newx = x + 1;
        newy = y;
        if (canMove(newx, newy, visited, maze, n))
        {
            path.push_back('R');
            solve(maze, ans, visited, newx, newy, path, n);
            path.pop_back();
        }
        // Up Step Condition :-
        newx = x;
        newy = y - 1;
        if (canMove(newx, newy, visited, maze, n))
        {
            path.push_back('U');
            solve(maze, ans, visited, newx, newy, path, n);
            path.pop_back();
        }
        // Down Step Condition :-
        newx = x;
        newy = y + 1;
        if (canMove(newx, newy, visited, maze, n))
        {
            path.push_back('D');
            solve(maze, ans, visited, newx, newy, path, n);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // Visited Array to check if its already visited at time of recursion :-
        vector<vector<int>> visited;
        for (int i = 0; i < maze.size(); i++)
        {
            for (int j = 0; j < maze.size(); j++)
            {
                visited[i][j] = 0;
            }
        }

        // Answer Array :-
        vector<string> ans;

        // Initiallize Position :-
        // String Path :-
        string path = "";

        // If (0,0) has a block :-
        if (maze[0][0] == 0)
        {
            return ans;
        }

        // Size of Maze :-
        int n = maze.size() - 1;
        solve(maze, ans, visited, 0, 0, path, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
