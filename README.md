# CS210-Programming-Languages

Summary: The Item Tracker Program was developed to address the needs of the Corner Grocer, a store looking to rearrange its produce section efficiently. This program processes text records generated throughout the day, listing items purchased in chronological order. It provides the following functionality:

Find Item Frequency: Allows users to input an item and returns the numeric value of its frequency. Print All Item Frequencies: Prints a list of all items with their respective frequencies. Print Item Histogram: Prints a histogram of items based on their frequencies. Data Backup: Automatically creates a data backup file, frequency.dat, with item frequencies.

What Was Done Well:

The program effectively reads data from an input file, processes it, and provides valuable insights into item frequencies. Code structure is modular, following best practices for C++ development, including the use of classes and organized header and implementation files. Input validation was implemented to handle potential user input errors, ensuring robustness.

Areas for Enhancement:

Error handling could be further improved to handle unexpected issues that might occur during file operations, such as file not found or file write errors. Enhancements to user interface design and error messaging can make the program more user-friendly. Testing with different data scenarios and edge cases would enhance the robustness of the program.

Challenging Code Sections: The code section related to input validation using a try-catch block was challenging but necessary to ensure that non-integer user input does not cause runtime errors. To overcome this challenge, we utilized exception handling and provided informative error messages to guide the user.

Transferable Skills:

File input and output operations in C++. Working with data structures, such as maps, to process and analyze data. Exception handling and input validation techniques. Maintainability and Readability: The program is organized into separate header, class, and main files, following C++ best practices. In-line comments were added to describe the functionality of code sections, making it more readable. Meaningful variable and function names were chosen to improve maintainability. Overall, the code is structured and documented to be adaptable to future changes and enhancements.
