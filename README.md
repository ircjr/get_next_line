<h1 align="center">
  📜 get_next_line 📜
</h1>

<p align="center">
  <b><i>Reading a line from a fd is way too tedious</i></b><br>
</p>

---

##  📚 About the project
> _This project is about programming a function that returns a line
read from a file descriptor._

    The get_next_line project is a fundamental exercise that challenges developers to create a
    function capable of reading a file line by line. In a broader context, this function becomes
    a crucial tool in handling input and output operations efficiently.

    Developers implementing get_next_line learn the intricacies of managing file descriptors, memory
    allocation, and buffer handling. This project delves into the heart of C programming, requiring
    a deep understanding of file I/O operations, dynamic memory allocation, and string manipulation.

    This function, when perfected, allows for seamless reading from multiple file descriptors
    simultaneously. It is an essential skill for anyone venturing into systems programming,
    file manipulation, or any domain where efficient text processing is paramount.

For more detailed information, check the [**subject of this project**](https://github.com/ircjr/get_next_line/blob/main/en.subject.pdf)

## 📖 Guide to get_next_line

## 📋 Testing

This command will compile your project and run the program, displaying the output with newline characters represented as **$**. Make sure to uncomment the main function in the [**get_next_line.c**](https://github.com/ircjr/get_next_line/blob/main/get_next_line.c) file before running and replace **<size>** with the desired buffer size.

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out | cat -e
```
The command remains the same for the bonus part of the project, just add the _bonus suffix to the source files.

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line_bonus.c get_next_line_utils_bonus.c && ./a.out | cat -e
```
