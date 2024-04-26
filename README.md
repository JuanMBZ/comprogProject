For improvements:
- remove new line from linked least, head straight to NULL after a \n, for displaying print a \n after encountering a NULL.

additional:
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


n Option
(clear terminal
place cursor to first position) create clear func for this block
initialize line linked list
read user key presses
(i for insert mode, cursorops, deletion, undo, etc.) dataops
(ctrl-s to save, ctrl-(idk) to save and quit, ctrl-x to quit without saving) fileops
after user inputs quit, clear terminal and place cursor to upper left corner before returning 

e Option
call clear func
load file into line linked list
display linked list
move cursor back to upper left
read user key press
dataops
fileops
reset terminal and exit

v Option
call clear func
load file into line linked list
display linked list
move cursor back to upper left
disable echo, dataops and fileops
reset terminal and exit


3 Modes for user editing
1. Navigation mode - while in this modeuser can input direction keys to move around the file and also input command keys such as undo, copy, delete, etc.
2. Writing mode - while in this mode the user can insert new characters into the text 
3. Selection mode - while in this mode the user can move around to select blocks/lines of text (to delete, copy, etc)
