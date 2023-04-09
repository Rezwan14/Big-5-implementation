[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9980114&assignment_repo_type=AssignmentRepo)
# Assignment 1

## Information about the repository

This repository contains the following:
- Starter code: `points2d.h`, `test_points2d.cc`,`test_input_file.txt`, `expected_output.txt`, `Makefile` and `README.md`
- Assignment specification: `Spring23-Assignment1.pdf`

## Running the assignment

You will use this exact `Makefile` for your Assignment 1. Failure to do so will result in *deduction* of points.

To compile on terminal, type:

```bash
make clean
make all
```

To delete executables and object files, type:

```bash
make clean
```

To run, type:

```bash
./test_points2d
```

## Providing Input from Standard Input

To run with a given file that is redirected to standard input:

```bash
./test_points2d < test_input_file.txt
```

## Challenges when doing assignment
Big-5:
For the most part, I felt most of the big-5 functions were simple. Most of the functions were only a few lines of code, and we simply had to set values to our private data members. 
Operators: 
I encountered the most challenges when I attempted the operator functions. I felt lost when attempting the ostream and istream at first. After some research I found out what I had to do. Although my program compiled at first, I kept getting compiler errors for my testpoints2.cc because I have not had my operator functions implemented. My compiler was unable to recognize cin>>. However, I implemented my istream and osteam along with my + function and there were no longer any compiler errors. 

Sometimes when I uploaded my files on gradescope, I only recieved partial credit for my big-5 functions. Perhaps this was because my operator functions was wrong. I had to include a cout<<'\n' at the end of my operator overload functions for it to finally work. 

Overall:
(i). All parts of my project was executed.
(ii). I used input file to implement my code for testing.
(ii). I used the output file to track my progress when testing my code. The output file however was not needed for this project.

