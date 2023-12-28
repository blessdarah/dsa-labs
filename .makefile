password: 
	gcc -Wall -o password password.c

ceasar: 
	gcc -Wall -o ceasar ceasar.c

bsearch: 
	gcc -Wall -o bsearch bsearch.c

factorial: 
	gcc -Wall -o factorial factorial.c

hashTable: 
	gcc -Wall -o hashTable hashTable.c

clean:
	rm -rf password ceasar bsearch factorial hashTable
