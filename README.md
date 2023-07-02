# Development Environment and Compilation Instructions

The development environment used for this code is Code::Blocks, a popular integrated development environment (IDE) for C and C++ programming. To compile and run the source code, please follow the instructions below:

## Prerequisites

- Code::Blocks IDE (Download and install from: [https://www.codeblocks.org/downloads/](https://www.codeblocks.org/downloads/))
- C Compiler (GCC or MinGW)

## Compilation Steps

1. Open Code::Blocks IDE.

2. Create a new empty project:
   - Go to "File" -> "New" -> "Project..."
   - Select "Empty project" and click "Go"
   - Choose a project name and location, then click "Next"
   - Leave the project type as "Console application" and click "Next"
   - Choose "C" as the programming language and click "Finish"

3. Add the source code to the project:
   - Right-click on the project name in the "Projects" pane.
   - Select "Add files recursively..." or "Add files..."
   - Locate the source code file ("main.c") and click "Open" or "Add"

4. Configure the project settings:
   - Right-click on the project name in the "Projects" pane.
   - Select "Build options..."
   - In the "Compiler settings" tab, make sure the appropriate compiler is selected.
   - In the "Linker settings" tab, ensure that the necessary libraries are included (e.g., "m" for math library).
   - Click "OK" to save the changes.

5. Build the project:
   - Go to "Build" -> "Build" or press the "F9" key.
   - The compilation process will start, and you should see the build messages in the "Build Log" pane.

6. Run the program:
   - Once the build is successful, go to "Build" -> "Run" or press the "Ctrl + F10" key.
   - The output of the program will be displayed in the "Build Log" pane or the console window.


## Functionality

The provided code demonstrates a simple expression evaluator using a binary expression tree. It supports various arithmetic operations, absolute value calculation, and Fibonacci number calculation. Here's a brief explanation of the code's functionality:

- The `TypeTag` enumeration defines different types of operations and literals that can be used in the expression tree.

- The `Node` structure represents a node in the expression tree. It contains the type of the node (operation or literal), the value (for literals), and pointers to the left and right child nodes.

- The `makeNode` function creates a new node with the given type and value.

- The `calc` function recursively calculates the value of a given node based on its type. It performs the corresponding operation or returns the literal value.

- The `fibonacci` function uses dynamic programming to calculate the Fibonacci number for a given input.

- The `makeFunc` macro defines a convenient way to create nodes for different operations. It takes two literal values as arguments and returns a new node representing the specified operation.

- The `makeValue` macro creates a node for a literal value.

- In the `main` function:
  - An array `fib` is initialized to store Fibonacci numbers.
  - Nodes are created using the `makeFunc` macro, and their values are calculated using the `calc` function.
  - The results are printed using `printf`.




