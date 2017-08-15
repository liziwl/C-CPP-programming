# Description
We use 2 method to implement the program.
Data structure:
* for single file, we use struct to store path, name, size, and some other info.
## find_dup
Using vector to store all structs, then we sort the vector in descending size. Finally, comparing the file in the same size and print them to `std::cout`.

There is a process indicator running in `std::cerr`, so if the user doesn't redirection, `cout` and `cerr` will mix in the Console to display.
## find_hash
Using hashtable to store all structs. Once we read the file, we will hash the size and compare it to the former files in the same size and insert the hashtable. We do the hole things in the function `listDir()`.

We print the current reading file in `std::cerr`. At last, we will print the same files in `std::cout`.
In this method, `cout` and `cerr` will not mix in the Console.
