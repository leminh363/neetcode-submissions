from collections import deque
class Solution:
    def pacificAtlantic(self, heights):
        rows = len(heights)
        cols = len(heights[0])

        # pacific
        pacificq = deque()
        pacificset = set()
        for c in range(cols):
            pacificq.append((0,c))
            pacificset.add((0,c))
        for r in range(rows):
            pacificq.append((r,0))
            pacificset.add((r,0))

        # atlantic
        atlanticq = deque()
        atlanticset = set()
        for c in range(cols):
            atlanticq.append((rows-1,c))
            atlanticset.add((rows-1,c))
        for r in range(rows):
            atlanticq.append((r,cols-1))
            atlanticset.add((r,cols-1))

        def bfs(q,ocean):
            directions = [(0,-1),(-1,0),(0,1),(1,0)]
            while q:
                r,c = q.popleft()
                for dr,dc in directions:
                    newrow = dr + r
                    newcol = dc + c
                    if 0 <= newrow < len(heights) \
                    and 0 <= newcol < (len(heights[0])) \
                    and (newrow,newcol) not in ocean \
                    and heights[newrow][newcol] >= heights[r][c]:
                        q.append((newrow,newcol))
                        ocean.add((newrow,newcol))

        bfs(pacificq,pacificset)
        bfs(atlanticq,atlanticset)

        res = []
        for r,c in pacificset:
            if (r,c) in atlanticset:
                res.append([r,c])
        return res

heights = [
  [4,2,7,3,4],
  [7,4,6,4,7],
  [6,3,5,3,6]
]
sol = Solution()
print(sol.pacificAtlantic(heights))
        