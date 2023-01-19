# pipex

-- P | P E X --

In this project you have to creatr a program that behaves like the following shell command:
```
$ in_file cmd1 | cmd2 > out_file
```
This program reads the contents of in_file as input passes it through cmd1 and then pipes the output to cmd2.\
The final output is written to out_file.

Installation:\
Clone the repository.

Usage:\
To use the program, run the following command:
```
$ make
```
```
$ ./pipex file1 "cmd1" "cmd2" file2
```
Examples:\
Here are some examples of how to use the program:\
1 - Copy code
```
$./pipex Makefile cat rev out_file
```
In this example we will show a reverse virsion of the content of the file "Makefile" in the file "outfile".\
2 - Copy code
```
$./pipex pipex.h cat "wc -l" out_file2
```
In this one , the number of line of "pipex.h" file will appear in the file "outfile2".
