from random import *
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import logging

FORMAT = '%(asctime)s %(message)s'

logging.basicConfig(filename='lab8.log', filemode='w', level=logging.INFO, format=FORMAT)

logger = logging.getLogger(__name__)
logger.level = logging.INFO


def getNextGap(gap):

    logger.info('getNextGap work.')
    gap = (gap * 10)//13

    if gap < 1:
        logger.info('getNextGap return 1.')
        return 1
    
    logger.info('getNextGap return gap.')
    return gap


def combSort(arr):
    logger.info('CombSort work.')
    n = len(arr)

    gap = n

    swapped = True

    while gap !=1 or swapped == 1:

        logger.info('Looking for a gap.')
        gap = getNextGap(gap)

        swapped = False

        for i in range(0, n-gap):

            if arr[i] > arr[i + gap]:

                logger.info('Displacement of elements.')
                plt.bar(i + 1,  height = arr, color = 'r')
                plt.bar(i + gap + 1,  height = arr, color = 'midnightblue')
                arr[i], arr[i + gap]=arr[i + gap], arr[i]
                yield arr
                swapped = True



def visualization(sort_alg, a):

    logger.info('Visualization.')
    generator = sort_alg(a)
    while True:
        
        next_a = next(generator, None)
        
        if next_a is None:
            logger.info('Break (while True)')
            break

        else:
            logger.info('Creating an image.')
            plt.title('Comb sort')
            plt.ylabel('Numders')
            
            plt.bar(x = range(1, len(a) + 1), height = a)
            
            plt.pause(0.1)
            plt.clf()        
            
    plt.title('Comb sort')
    plt.ylabel('Numders')   
    plt.bar(x = range(1, len(a) + 1), height = a)
    plt.show()

if __name__ == "__main__":

    plt.style.use('dark_background')
    N = int(input("Enter number of elements: "))
    A = [randint(1,2390) for j in range(N)]
    
    print(A)
    visualization(combSort, A)
    print(A)
    
