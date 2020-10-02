To compile the files use command:
gcc -o exer profile_main.c parser.c parser.h hash.c hash.h collision_count.c collision_count.h

To run use command:
./exer

NOTE-
1)Each word has sum of ascii values around 1000-3000.
2)The table size and prime numbers which have been asked to be used are all larger than 5000.
3)So the hash function is useless as %(any number greater than 5000 will have no effect on the sum). 
4)basically this hash function is the same as the hash function sum of ascii values with no mod of tablesize and basenumber.
5)Hence all collisions will be the same in all cases since the hash function is independent of tablesize and basenumber.

Conclusions:
1) A hash function with a lower base number is required to vary the results and make it useful.
2) All the results will be the same and cause same number of collisions.
