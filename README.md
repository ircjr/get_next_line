<h1 align="center">
	📜 get_next_line 📜
</h1>

<p align="center">
	<b><i>Reading a line from a fd is way too tedious</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/ircjr/get_next_line?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/ircjr/get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/ircjr/get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ircjr/get_next_line?color=green" />
</p>

---

##  🗣️ About the Project
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

### 1️⃣ Understanding the Basics

#### 1️⃣.1️⃣ MANDATORY PART

Function name: `get_next_line`

Prototype: `char  *get_next_line(int fd);`

Turn in files: `get_next_line.c, get_next_line_utils.c, get_next_line.h`

Parameters: `fd: The file descriptor to read from`

Return value: `Read line: correct behavior` or `NULL: there is nothing else to read, or an error occurred`

External functs.: `read, malloc, free`

Description: `Write a function that returns a line read from a file descriptor`

#### 1️⃣.2️⃣ REQUIREMENTS FOR THE MANDATORY PART
* Repeated calls (e.g., using a loop) to your `get_next_line()` function should let you read the text file pointed to by the file descriptor, **one line at a time**.
* Your function should return **the line that was read**. If there is nothing else to read or if an error occurred, it should return `NULL`.
* Make sure that your function works as expected both when reading a file and when reading from the standard input.
* **Please note** that the returned line should include the terminating `\n` character, except if the end of file was reached and does not end with a ``\n`` character.
* Your header file ``get_next_line.h`` must at least contain the prototype of the ``get_next_line()`` function.
* Add all the helper functions you need in the ``get_next_line_utils.c`` file.

**OBS.:** Try to read as little as possible each time ``get_next_line()`` is called. If you encounter a new line, you have to return the current line. Don’t read the whole file and then process each line.

#### 1️⃣.3️⃣ FORBIDDEN

* You are not allowed to use your **libft** in this project.
* ``lseek()`` is forbidden.
* **Global variables** are forbidden.

#### 1️⃣.4️⃣ BONUS PART

In the bonus part, this state management extends to multiple file descriptors.

#### 1️⃣.5️⃣ REQUIREMENTS FOR THE BONUS PART
* Develop `get_next_line()` using only one **static variable**.
* Your `get_next_line()` can manage multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another **fd**. It means that you should be able to call `get_next_line()` to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.

Append the **_bonus.[c\h]** suffix to the bonus part files.

It means that, in addition to the mandatory part files, you will turn in the 3 following files:
* `get_next_line_bonus.c`
* `get_next_line_bonus.h`
* `get_next_line_utils_bonus.c`

## 2️⃣ Files

#### get_next_line.c

	The file get_next_line.c contains the implementation of the get_next_line() function.

#### get_next_line_utils.c

	The file get_next_line_utils.c contains auxiliary utility functions to support the implementation 
 	of the get_next_line() function.
 
#### get_next_line.h

	The get_next_line.h file is a C header that contains, at a minimum, the declaration of the
 	get_next_line() function. It serves as an interface providing the function's signature,
  	enabling other source files to use this function without needing to be aware of its detailed implementation.

## 3️⃣ Implemention Details

#### 3️⃣.1️⃣ STATIC VARIABLES

A good start would be to know what a **static variable** is.

So what is a **static variable**?

Basically, a **static variable** is a variable that maintains its value between function calls, staying in memory throughout the program's execution. It is initialized only once and retains its value between calls, being accessible only within the scope of the function where it was declared.

For more detailed information, check the Wikipedia on [**static variable**](https://en.wikipedia.org/wiki/Static_variable)

This code is a practical example of how a **static variable** can work:

<details><summary><b>Show the code</b></summary>

```
#include <stdio.h>

int	count_calls(void)
{
	static int	count = 0;

	count++;
	return (count);
}

int	main(void)
{
	printf("%d\n", count_calls());
	printf("%d\n", count_calls());
	printf("%d\n", count_calls());
	return (0);
}
```

The compilation and execution of the above code bring us the following result:

```
1
2
3
```

Now, we can see the essence of a **static variable**, which is the ability to retain its value between function calls.

</details>

#### 3️⃣.2️⃣ BUFFER SIZE

The `BUFFER_SIZE` macro determines the size of the buffer used to read from the file descriptor. It can be adjusted based on your requirements.

So what is a **buffer**?

Basically, a buffer is a temporary storage area that holds data while it is being transferred from one place to another.

And what do we mean by `BUFFER_SIZE`?

In programming, especially in the context of the `get_next_line` project, `BUFFER_SIZE` refers to the size of the buffer used to read data from a file or another input source. It is a parameter that determines how many characters or bytes will be read in each reading operation.

In other words, we are reading data from a file in chunks or **"buffers"** of size `BUFFER_SIZE`.

Below, we can see how the `BUFFER_SIZE` macro can be defined in our header file to be used in both our code and by the compiler:

<details><summary><b>Show the code</b></summary>

```
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
```

The choice of the value **42** to initialize `BUFFER_SIZE` was made arbitrarily, you can choose any value you prefer.

</details>

## 4️⃣ Coding

The page is blank...

## 📋 Testing

This command will compile your project and run the program, displaying the output with newline characters represented as `$`. Make sure to uncomment the main function in the `get_next_line.c` file before running and replace **<size>** with the desired buffer size.

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out | cat -e
```
The command remains the same for the bonus part of the project, just add the **_bonus** suffix to the source files.

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line_bonus.c get_next_line_utils_bonus.c && ./a.out | cat -e
```
