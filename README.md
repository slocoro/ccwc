# wc

[Coding Challenge](https://codingchallenges.fyi/challenges/challenge-wc/) - Build your own `wc` tool

Written in C for learning purposes.

### Build

```
make build file=ccwc.c
```

### Usage

Count bytes:
```
./ccwc -c test.txt
```

Count lines:
```
./ccwc -l test.txt
```

Count words:
```
./ccwc -w test.txt
```

Pipe from cat:
```
cat test.txt | ./ccwc -c
```

All:
```
./ccwc test.txt
```

### Learnings
- You can read from the standard input using the special variable `stdin`. It behaves (or maybe is) like a file pointer `FILE`
- Counting bytes and counting characters is different, some characters are >1 byte long
- When reading a file one byte at a time store the bytes in a "buffer" so they can be used (e.g. identify multibyte characters)
- `char *argv[]` is "an array of character pointer" (not the actual "string", although there are no strings in C)
- If you want to iterate over a file for a second time you first have to reset the pointer to the beginning of the file.
- When passing a variable pointer to a function (e.g. int *count), you need to dereference it (i.e.
if you want to change its value. Otherwise you are changing the value of the pointer (i.e. address)

### TODO
- make `count_characters` work correclty
- add unit tests

#### References

- https://www.geeksforgeeks.org/format-specifiers-in-c/
- https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm
- https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/#1-read-a-file-in-c-using-fgetc
