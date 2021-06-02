# brennanb2021_Shell

# Program description:  
Continually prompts the user (‘>’) for one line of input.  
If the user inputs Control-D by itself, then the program exits.  
If  the  user  inputs  Control-C,  then  the  program  outputs “Shell  Exit-ing...” and exits.  
One line of processes:   
    1. processes are separated by one of {|,<,>}  
    2. words can be separated by one of {|,<,>} or a space  
    3. the first word in a process is its command  
    4. all words after the first, up to the end of a process, are arguments for the process  
    5. single quotes and double quotes surround one “word”, ignore characters from Item 2 above, and must match to be complete  
    6. matched quotes are not included in the argument or command  
    7. empty words and processes are ignored
If quotes are mismatched, the program prints “Mismatched Quotes"  
After each input, program outputs the following for each process:  
    –Process <NUMBER>  
    –Command: <COMMAND>  
    –Arguments:  
        –0: <ARG0>  
        –1: <ARG1>  
        –...  
   
# How to use it:  
-Navigate to the brennan_SHELL folder  
-Run the makefile: "make all"  
-Run the executable called shell: 
"./shell" (at least on linux)  
The program will prompt you for input.

# How to run unit tests:  
-Navigate to the brennan_SHELL folder  
-Run the makefile: "make test"  
-Run the unit test file: "./test_runner"  
