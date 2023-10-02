# Convert decimal values (integers) to specified [8/16/32/64] binary format

## Installation

to compile the project run:
```bash
make
```

to compile it with debugging option use:
```bash
make debug-pars		#to get parsing info
```
or
```bash
make debug-val		# to get values info being set into binary format
```

## Usage

to run it, specify the binary format (--b) and bit size (--f16, --f32, etc.)
```bash
./main --b --f16 6 -1 128 42 4 256
```

- pass any number of integers to the executable

```bash
./main --b --f32 -1 1 3 4 -10 14 4096 -5t - 9x 7
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
