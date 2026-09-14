from collections import deque
class Solution:
    def islandsAndTreasure(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        treasure = deque()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    treasure.append((r,c))

        def bfs():
            directions = [(0,-1),(-1,0),(0,1),(1,0)]
            while treasure:
                r,c = treasure.popleft()
                for nr,nc in directions:
                    newrow = r+nr
                    newcol = c+nc
                    if 0 <= newrow < len(grid) and 0 <= newcol < len(grid[0]) and grid[newrow][newcol] == 2147483647:
                        grid[newrow][newcol] = grid[r][c] + 1
                        treasure.append((newrow,newcol))

        bfs()
                    
grid=[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]

