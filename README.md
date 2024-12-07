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
./ccwc test.txt
# or
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

#### References

- https://www.geeksforgeeks.org/format-specifiers-in-c/
- https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm
- https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/#1-read-a-file-in-c-using-fgetc
