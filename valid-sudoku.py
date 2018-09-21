# Inefficient AF

class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        
        self.board = board
        
        cols = [list() for i in range(9)]
        boxes = [list() for i in range(9)]
        
        # Filter rows first
        for n, i in enumerate(map(self.howMany, self.board)):
            if i != len(set(board[n])):
                return False
        
        # Now filter cols
        for i in range(9):
            if self.checkCols(i) is not True:
                return False
        
        # Now the tough one
        for i in range(3):
            for j in range(3):
                if self.checkBoxes(i*3, j*3) is not True:
                    return False
                
        return True
    
    def howMany(self, row):
        
        total = 0
        for i in row:
            if i != ".":
                total += 1
        return total if total == 9 else total+1
    
    def checkCols(self, i):

        col = [self.board[j][i] for j in range(9)]
        return self.howMany(col) == len(set(col))

    def checkBoxes(self, i, j):
        
        box = list()
        for m in range(3):
            for n in self.board[i][j:j+3]:
                box.append(n)
            i += 1

        return self.howMany(box) == len(set(box))
