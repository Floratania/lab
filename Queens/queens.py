import logging

FORMAT = '%(asctime)s %(message)s'

logging.basicConfig(filename='queens.log', filemode='w', level=logging.INFO, format=FORMAT)

logger = logging.getLogger(__name__)
logger.level = logging.INFO



def isSafe(board, row, col):
    

    
    
    for i in range(row):

        if board[i][col] == 'Q':

            logger.info('isSafe return false, because two queens share the same column.')
            return False

    (i, j) = (row, col)
    while i >= 0 and j >= 0:

        if board[i][j] == 'Q':

            logger.info('isSafe return false, because two queens share the same \ diagonal.')
            return False
        
        i = i - 1
        j = j - 1
 
 
    (i, j) = (row, col)
    while i >= 0 and j < len(board):

        if board[i][j] == 'Q':

            logger.info('isSafe return false, because two queens share the same / diagonal.')
            return False
        
        i = i - 1
        j = j + 1

    logger.info('isSafe return true.')
    return True
 

def printBoard(board):

    for r in board:
        print(str(r).replace(',', '').replace('\'', ''))
    print()
 
 
def nQueen(board, row):

    
    if row == len(board):
        printBoard(board)

        logger.info(' N queens are placed successfully.')
        return
 
 
    for i in range(len(board)):

        if isSafe(board, row, i):

            logger.info('Place queen on the current square.')
            board[row][i] = 'Q'

            logger.info('nQueen for the next row.')
            nQueen(board, row + 1)

            logger.info('Backtrack, remove the queen from the current square.')
            board[row][i] = '.'

 

if __name__ == "__main__":

    N = 8

    board = [['.' for _ in range(N)] for _ in range(N)]

    nQueen(board, 0)