# Convert integers to binary / hexadecimal / octal values

## Installation

to compile the project run:
```bash
make
```

to compile it with debugging option use:
```bash
make debug-pars		# to get parsing info
```
or
```bash
make debug-val		# to get values while being set into binary format
```

## Usage

to run it, specify the needed system:

- binary system [--b] and bit size [--s16, --s32, etc.]

```bash
./main --b --s16 
```

- hexadecimal system [--x] and upper/lower case [--U, --u]

```bash
./main --x --U
```

- octal system [--o]

```bash
./main --o
```


* Pass any number of integers using a shell variable

```bash
ARG="-1 2 3 4 5 32"
./main --b --s32 $ARG
```

- another way of passing arguments to the program:

```bash
./main --b --s32 -1 1 3 4 -10 14 4096 -5t - 9x 7
```

The given output looks as follows:
```
input value: [-1  ]  binary value: 11111111111111111111111111111111
input value: [1   ]  binary value: 00000000000000000000000000000001
input value: [3   ]  binary value: 00000000000000000000000000000011
input value: [4   ]  binary value: 00000000000000000000000000000100
input value: [-10 ]  binary value: 11111111111111111111111111110110
input value: [14  ]  binary value: 00000000000000000000000000001110
input value: [4096]  binary value: 00000000000000000001000000000000
Invalid number : -5t
Invalid number : -
Invalid number : 9x
input value: [7   ]  binary value: 00000000000000000000000000000111
```
