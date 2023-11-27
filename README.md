<p align="center">
	<img src="https://user-images.githubusercontent.com/102881479/215228915-72cdc235-c3b5-4793-be79-e5e2f36d8336.png">
</p>

<p align="center">
	<b><i>Reading a line from a fd is way too tedious</i></b><br>
</p>

<p align="center">
	<img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language">
	<img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
	<img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
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

---

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
* **Please note** that the returned line should include the terminating `\n` (newline character), except if the `EOF` (end of file) was reached and does not end with a `\n` (newline character).
* Your header file `get_next_line.h` must at least contain the prototype of the `get_next_line()` function.
* Add all the helper functions you need in the `get_next_line_utils.c` file.

**OBS.:** Try to read as little as possible each time `get_next_line()` is called. If you encounter a `\n` (newline character), you have to return the current line. Don’t read the whole file and then process each line.

#### 1️⃣.3️⃣ FORBIDDEN
* You are not allowed to use your **libft** in this project.
* `lseek()` is forbidden.
* **Global variables** are forbidden.

#### 1️⃣.4️⃣ BONUS PART
In the bonus part, this state management extends to **multiple file descriptors**.

#### 1️⃣.5️⃣ REQUIREMENTS FOR THE BONUS PART
* Develop `get_next_line()` using only one **static variable**.
* Your `get_next_line()` can manage multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another **fd**. It means that you should be able to call `get_next_line()` to read from **fd** 3, then **fd** 4, then 5, then once again 3, once again 4, and so forth.

Append the **_bonus.[c\h]** suffix to the bonus part files.

It means that, in addition to the mandatory part files, you will turn in the 3 following files:
* `get_next_line_bonus.c`
* `get_next_line_bonus.h`
* `get_next_line_utils_bonus.c`

### 2️⃣ Files
#### get_next_line.c

	The file get_next_line.c contains the implementation of the get_next_line() function.

#### get_next_line_utils.c

	The file get_next_line_utils.c contains auxiliary utility functions to support the implementation 
 	of the get_next_line() function.
 
#### get_next_line.h

	The get_next_line.h file is a C header that contains, at a minimum, the declaration of the
 	get_next_line() function. It serves as an interface providing the function's signature,
  	enabling other source files to use this function without needing to be aware of its detailed implementation.

### 3️⃣ Implemention Details
#### 3️⃣.1️⃣ STATIC VARIABLES

A good start would be to know what a **static variable** is.

So what is a **static variable**?

Basically, a **static variable** is a variable that maintains its value between function calls, staying in memory throughout the program's execution. It is initialized only once and retains its value between calls, being accessible only within the scope of the function where it was declared.

This code is a practical example of how a **static variable** can work:

<details><summary><b>Show the code</b></summary>

```c
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

For more detailed information, check the Wikipedia on [**static variable**](https://en.wikipedia.org/wiki/Static_variable)

#### 3️⃣.2️⃣ BUFFER SIZE
The `BUFFER_SIZE` macro determines the size of the buffer used to read from the file descriptor. It can be adjusted based on your requirements.

So what is a **buffer**?

Basically, a buffer is a temporary storage area that holds data while it is being transferred from one place to another.

And what do we mean by `BUFFER_SIZE`?

In programming, especially in the context of the `get_next_line` project, `BUFFER_SIZE` refers to the size of the buffer used to read data from a file or another input source. It is a parameter that determines how many characters or bytes will be read in each reading operation.

In other words, we are reading data from a file in chunks or **"buffers"** of size `BUFFER_SIZE`.

Below, we can see how the `BUFFER_SIZE` macro can be defined in our header file to be used in both our code and by the compiler:

<details><summary><b>Show the code</b></summary>

```c
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
```

The choice of the value **42** to initialize `BUFFER_SIZE` was made arbitrarily, you can choose any value you prefer.

</details>

### 4️⃣ Coding
get_next_line.h

<details><summary><b>Show the code</b></summary>

```c
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
```

</details>

get_next_line.c

<details><summary><b>Show the code</b></summary>

```c
#include "get_next_line.h"

char	*read_from_fd(int fd, char *buffer, char *stash)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*obtain_next_line(char *line)
{
	size_t	i;
	char	*stash;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (NULL);
	stash = ft_substr(line, (i + 1), (ft_strlen(line) - i));
	if (!*stash)
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_from_fd(fd, buffer, stash);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = obtain_next_line(line);
	return (line);
}
```

</details>

get_next_line_utils.c

<details><summary><b>Show the code</b></summary>

```c
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) \
		* sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s[++i])
		result[i] = s[i];
	result[i] = '\0';
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && i < len)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
```

</details>

---

## 🛠️ Usage
To incorporate the functionality of ``get_next_line()`` into your project, it is essential to include the three mentioned files during the compilation phase. This applies to both mandatory and bonus files.

To use the ``get_next_line()`` function in your project, make sure to include the corresponding header.

For the mandatory part:

```c
#include "get_next_line"
```

For the bonus part:

```c
#include "get_next_line_bonus"
```

---

## 📋 Testing
This command will compile your project and run the program, displaying the output with newline characters represented as `$`. Make sure to uncomment the main function in the `get_next_line.c` file before running and replace **<size>** with the desired buffer size.

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out | cat -e
```
The command remains the same for the bonus part of the project, just add the **_bonus** suffix to the source files.

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line_bonus.c get_next_line_utils_bonus.c && ./a.out | cat -e
```
