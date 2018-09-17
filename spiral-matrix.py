class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        ret = list()
        
        # Helper variables.
        row_min = 0; col_min = 0
        row_max = len(matrix[0])
        col_max = len(matrix)
        total_elems = row_max * col_max
        row_flip = True                      # Loop through row left to right when true and otherwise.
        col_flip = True                      # Loop from top to bottom when true and otherwise
        flip_bit = True                      # Traverse row when true or column otherwise
        
        # Sometimes you have to forget that there's something called cache :D
        while (len(ret) != total_elems):
            
            # print ("row_min: ", row_min, " : row_max : ", row_max, " : col_min : ", col_min, " col_max : ", col_max)
            if (row_min == row_max or col_min == col_max):
                break

            if flip_bit:
                
                if row_flip:
                    for i in matrix[col_min][row_min:row_max]:
                        ret.append(i)
                    col_min += 1
                    flip_bit = not flip_bit
                    row_flip = not row_flip

                else:
                    for i in reversed(matrix[col_max-1][row_min:row_max]):
                        ret.append(i)
                    col_max -= 1
                    flip_bit = not flip_bit
                    row_flip = not row_flip
                    
                    
            else:
                
                if col_flip:
                    for i in range(col_min, col_max):
                        ret.append(matrix[i][row_max-1])
                    row_max -= 1
                    flip_bit = not flip_bit
                    col_flip = not col_flip
                    
                else:
                    for i in reversed(range(col_min, col_max)):
                        ret.append(matrix[i][row_min])
                    row_min += 1
                    flip_bit = not flip_bit
                    col_flip = not col_flip
                    
                    
        return ret
                        
                        
 



sol = Solution()
mat = [[1,2,3],[4,5,6],[7,8,9]]
ret = sol.spiralOrder(mat)
print (str(ret))