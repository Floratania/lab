import logging

FORMAT = '%(asctime)s %(message)s'

logging.basicConfig(filename='lab.log', filemode='w', level=logging.INFO, format=FORMAT)

logger = logging.getLogger(__name__)
logger.level = logging.INFO

def display_hash(hashTable): 

    logger.info("Display HashTable.")

    for i in range(len(hashTable)): 

        print(i, end = " ") 

        for j in hashTable[i]: 

            print("->", end = " ") 

            print(j, end = " ") 


        print() 



def Hashing(value):

    logger.info("Hashing") 

    return abs((2004 % 8) + len(value)) 

 

def insert(Hashtable, keyvalue, value): 
    
    logger.info("Insert.")

    hash_key = Hashing(keyvalue) 

    Hashtable[hash_key].append(value) 


if __name__ == "__main__":
    
    logger.info("Create HashTable.")
    HashTable = [[] for _ in range(30)] 

    insert(HashTable, 'sensations', 'often') 
    insert(HashTable, 'sfhaksfkalsfc', 'push') 
    insert(HashTable, 'ppppppppppppppppp', 'socket') 
    insert(HashTable, 'avoid', 'draw') 
    insert(HashTable, 'relax', 'taxi') 
    insert(HashTable, 'driver', 'car') 
    insert(HashTable, 'fast', 'fresh') 
    insert(HashTable, 'pen', 'phone') 
    insert(HashTable, 'test', 'boom') 
    insert(HashTable, 'stast', 'free time') 
 
    insert(HashTable, 'sensation', 'offer') 
    insert(HashTable, 'offer', 'heir') 
    insert(HashTable, 'society', 'society') 
    insert(HashTable, 'affinity', 'drawer') 
    insert(HashTable, 'relevance', 'Put') 
    insert(HashTable, 'dead', 'No') 
    insert(HashTable, 'far', 'off') 
    insert(HashTable, 'offers', 'rush') 
    insert(HashTable, 'terrace', 'bottom') 
    insert(HashTable, 'sector', 'free') 
    insert(HashTable, 'essential', 'cup') 
    insert(HashTable, 'I', 'Not') 
    insert(HashTable, 'mom', 'home') 
    insert(HashTable, 'sun', 'air') 
    insert(HashTable, 'scan', 'stack') 
    insert(HashTable, 'clearance', 'cold') 
    insert(HashTable, 'shout', 'cut') 
    insert(HashTable, 'alarm', 'domestic') 
    insert(HashTable, 'bedroom', 'on') 
    insert(HashTable, 'designer', 'designer') 
    insert(HashTable, 'spare', 'relate') 
    insert(HashTable, 'groan', 'action') 
    insert(HashTable, 'book', 'author') 
    insert(HashTable, 'my', 'SQL') 
    insert(HashTable, 'you', 'your')

    


display_hash (HashTable) 