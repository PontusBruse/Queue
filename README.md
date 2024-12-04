# Circular Singly Linked List Queue
## Overview
This project implements a **multiple instance circular singly linked list queue** in C++. The queue stores `int` data elements and provides functionalities such as adding, reading, clearing, resizing, and destroying the queue. The implementation supports overwriting the oldest data when the queue is full and includes robust testing with assertions.
________________________________________

## Features ##
1. **Create an instance
 -  Initializes a circular singly linked list with a specified size (must be greater than 3).
 
2. **Insert data  
 -  Adds data to the queue and overwrites the oldest data if the queue is full.
 
3. **Read data  
-  Retrieves and removes the oldest data from the queue.

4. **Clear the queue  
-  Empties the queue by clearing all stored data.

5. **Data count  
-  Returns the number of elements currently stored in the queue.

6. **Check if full  
-  Determines whether the queue has reached its capacity.

7. **Resize the queue  
-  Changes the size of the queue dynamically, maintaining its circular nature.
-  Ensures the new size is greater than 3. Removes the oldest data if the size is reduced below the current count.

8. **Destroy the queue  
-  Releases all allocated memory associated with the queue.
________________________________________

## Project Structure
```plaintext
.
├── queue.h        # Header file defining the queue interface.
├── queue.cpp      # Implementation of the queue functions.
├── main.cpp       # Test file using assertions to validate functionality.
├── Makefile       # Build and run management.
├── build/         # Directory for generated build files.
```
________________________________________

## Usage
### Compilation and Execution  
1. Clone the repository and navigate to the project folder.
2. Build the project using the provided Makefile:
```bash
make
```

3. Run the program:
```bash
make run
```
4. To clean the build directory:
```bash
make clean
```
________________________________________

## Example Output  
Below is an example of the expected output when running the test program:  

```bash
1 3 3 7 
```
________________________________________

## Testing  
The module is tested using assert statements to ensure all functionalities meet the specified requirements. The tests include:  
 -  Creating queues with valid and invalid sizes.
-  Inserting, reading, and clearing data.
-  Checking data count and full status.
-  Resizing the queue and validating memory management.
-  Destroying the queue and ensuring no memory leaks.
________________________________________

## Requirements  
To fulfill the assignment criteria:
-  **All required functionalities** (create, insert, read, clear, etc.) have been implemented.
-  **Assertions** validate the correctness of the module.
-  **Makefile** handles the build and test process.
-  Memory safety is ensured, and error handling is implemented for edge cases (e.g., invalid sizes, memory allocation failures).
________________________________________

** Author
Pontus Brusewitz
