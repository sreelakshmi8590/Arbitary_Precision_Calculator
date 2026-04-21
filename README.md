📌 Description
A high-performance command-line application written in C designed to overcome the limitations of standard data types (like int or double). This Arbitrary Precision Calculator (APC) can perform arithmetic operations on numbers of virtually any size—limited only by your system's memory—making it ideal for cryptographic applications or massive scientific computations.

🚀 Features
Infinite Precision: Handles numbers with hundreds or thousands of digits without overflow.
Core Arithmetic: Supports Addition, Subtraction, Multiplication, and Division of large integers.
Signed Operations: Correctly handles calculations involving both positive and negative large numbers.
Efficient Memory Management: Utilizes Doubly Linked Lists to store each digit, ensuring dynamic scaling and easy bidirectional traversal during carries and borrows.
Automated Validation: Ensures inputs are valid numerical strings before processing.

🛠️ Technologies Used
C Programming
Data Structures: Doubly Linked Lists
Dynamic Memory Allocation: malloc, calloc, and free
Algorithms: Manual "Schoolbook" Arithmetic implementation

📂 Project Structure
Plaintext
Arbitary_Precision_Calculator/
├── APC/
├── main.c          # Main driver (menu-driven interface)
├── addition.c      # Logic for large number addition
├── subtraction.c   # Logic for large number subtraction
├── multiplication.c # Logic for large number multiplication
├── division.c       # Logic for large number division  
├── apc.h           # Function prototypes and struct definitions

💡 Key Concepts
Linked List Representation: Each node in the doubly linked list stores a single digit (or a block of digits). This allows the "number" to grow dynamically as the calculation progresses.
Operator Overloading (Logic): Since C doesn't support native operator overloading, the project implements custom logic to determine which mathematical algorithm to trigger based on the signs of the operands.
Carry & Borrow Logic: Replicates manual mathematics by traversing the linked lists from the tail (least significant digit) to the head (most significant digit), handling carries for addition/multiplication and borrows for subtraction.
