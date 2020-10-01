# Programing-Languages
This repository contains course work in 3 different languages, Prolog, Common LISP, and C. All 3 programs
where completed for a course at the California State University of San Marcos. All work was completed independenlty.

## Prolog:  
The program answers simple queries such as; "Which students have satisfied the requirements?" - degree(X),
and "What are the elective requirements fulfilled by a student?" - taken(student, X).
The program compiles and runs fine, however there is a bug in the "degree(X)." query. The program
will display the correct names, however it will display them multiple times.

## Common LISP: 
The program encrypts English words using the Cesar Cypher method, it can also decrypts words.
The program is not finished, however it compiles
and runs fine. As input it can only take in a list of
atoms, it does not support list of list.
All encryption and decryption is correct, however the
program does have an issue decrypting 'r' back to 'm'.
Methods of input: (encrypt'(c o m p u t e r)), (decrypt'(h t r y z u j w))
		
## C: 
The program converts english words to NATO words and NATO words to english
words. The method of input for this program is a file called "words.txt" which can be created by the user
