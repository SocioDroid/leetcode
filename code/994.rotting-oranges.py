class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        minute = 0
        
        rows = len(grid)
        columns = len(grid[0])
        
        def check_1(x, y):
            return True if grid[x][y] == 1 else False
        
        def rot(x,y, bool):    
            
            if x-1 >= 0:
                if check_1(x-1, y):
                    grid[x-1][y] = 2
                    bool = True
                                
            if x+1 < rows:
                if check_1(x+1, y):
                    grid[x+1][y] = 2
                    bool = True
                
            if y-1 >= 0:
                if check_1(x, y-1):
                    grid[x][y-1] = 2
                    bool = True
                    
            if y+1 < columns:
                if check_1(x, y+1):
                    grid[x][y+1] = 2
                    bool = True
            return bool
        
        for _ in range(100):
            coordinates = []
            one = []
            flag = False
            for x in range(rows):                
                for y in range(columns):
                    if grid[x][y] == 2:
                        grid[x][y] = 3
                        coordinates.append([x,y])                        
                    if grid[x][y] == 1:
                        one.append([x,y])

            if len(coordinates) == 0 and len(one) != 0:     
                return -1
            if len(coordinates) == 0:                
                break
            for i in range(len(coordinates)):
                flag = rot(coordinates[i][0], coordinates[i][1], flag)
            
            # print(flag)
            if flag:
                minute += 1
                
            # print(grid, minute)
        return minute
            
            
                
            
        