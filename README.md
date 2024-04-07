additional:
- use putchar/fputchar instead of printf
- add code for undo
- add code for search and replace
basic algorithm:
3 main stages of program
  1. prepare terminal, and prepare file input/output
  2. read user key presses to display and/or change file data
  3. save everything to file, free all memory and quit 

read user input from argv
if user input=n: create new file with specified directory and name
else if =e: open file from specified director if file dne return error
else if =v: open file to be read only
if no specific directory given create/edit/view file from current directory

l
n Mode
(clear terminal
place cursor to first position) create clear func for this block
initialize line linked list
read user key presses
(i for insert mode, cursorops, deletion, undo, etc.) dataops
(ctrl-s to save, ctrl-(idk) to save and quit, ctrl-x to quit without saving) fileops
after user inputs quit, clear terminal and place cursor to upper left corner before returning 

e Mode
call clear func
load file into line linked list
move cursor back to upper left
read user key press
dataops
fileops
reset terminal and exit

v Mode
call clear func
load file into line linked list
move cursor back to upper left
disable echo, dataops and fileops
reset terminal and exit
