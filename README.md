# make-change
### The Program:
Suppose that the available coins are in the denominations that are powers of c, i.e., the denominations are c0; c1; …; ck for some integers c > 1 and k > 1. Implement the greedy algorithm to address this task, picking the largest denomination first to yield an optimal solution. Your program should read a text file “data.txt" where each line in “data.txt" contains three values c, k and n. Please make sure you take your input in the specified order c, k and n. For example, a line in “data.txt" may look like the following: 
4   3   73    
where c = 4; k = 3; n = 73. That is, the set of denominations is {40; 41; 42; 43} = {1; 4; 16; 64}, and we would like to make change for n = 73. The file “data.txt” may include multiple lines like above.  
 
The output will be written to a file called “change.txt”, where the output corresponding to each input line contains a few lines. Each line has two numbers, where the first number denotes a denomination and the second number represents the cardinality of that denomination in the solution. For example, for the above input line ‘4 3 73’, the optimal solution is the multiset {64; 4; 4; 1}, and the output in the file “change.txt” is as follows:  

Data input: c = 4, k = 3, n = 73  
Denomination: 64 Quantity: 1  
Denomination: 16 Quantity: none  
Denomination: 4 Quantity: 2 
Denomination: 1 Quantity: 1 
 
which means the solution contains one coin of denomination 64, none of 16, two coins of 4, and one coin of 1. You can use a delimiter line to separate the outputs generated for different input lines.

## To Run the Program:
1. Give yourself permission to the compiler using: "chmod 777 compileall".
2. Run "compileall" to compile the code.
3. To run the program, type "makeChange"