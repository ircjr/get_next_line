<h1 align="center">
  📜 get_next_line 📜
</h1>

<p align="center">
  <b><i>Reading a line from a fd is way too tedious</i></b><br>
</p>

## About the project
> _This project is about programming a function that returns a line
read from a file descriptor._

## 📋 Testing

This command will compile your project and run the program, displaying the output with newline characters represented as **$**. Make sure to uncomment the main function in the **get_next_line.c** file before running and replace **<size>** with the desired buffer size.

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out | cat -e
```
