from collections import deque
class Solution:
    def orangesRotting(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        rottenfruit = deque()
        minutecount = -1
        fresh = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    fresh += 1
                elif grid[r][c] == 2:
                    rottenfruit.append((r,c))

        if not rottenfruit:
            return 0 if fresh == 0 else -1
        def bfs():
            while rottenfruit:
                nonlocal minutecount,fresh
                for _ in range(len(rottenfruit)):
                    directions = [(-1,0),(0,1),(1,0),(0,-1)]
                    fr, fc = rottenfruit.popleft()
                    for r,c in directions:
                        infectedrow = fr + r
                        infectedcol = fc + c
                        if 0 <= infectedrow < len(grid) and 0 <= infectedcol < len(grid[0]) and grid[infectedrow][infectedcol] == 1:
                            grid[infectedrow][infectedcol] = 2
                            fresh-=1
                            rottenfruit.append((infectedrow,infectedcol))
                minutecount += 1
        bfs()
        if fresh > 0:
            return -1

        return minutecount
grid = [[1,1,0],[0,1,1],[0,1,2]]
sol = Solution()
print(sol.orangesRotting(grid))


        