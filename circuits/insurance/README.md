# Car Insurance Calculator

### Building the circuit

Assuming the framework has been built (see top-level README), the car
insurance calculator can be compiled using the command in the
top-level directory:

```
bash make.sh
```

### Description

This directory contains the car insurance example mentioned in our
Poster.

The insurance calculator application consists of 15 different
components (excluding `main`), 6 of which are private. The source code
for each component resides in the respective C source file
(e.g. `damage.pub.c`). The `.pub.c` or `.priv.c` designate public or
private parts respectively.

The composition of all public boolean circuits and UCs is defined in
the `insurance.merge`. The syntax of this file is described in the
following section.

#### Merge File Syntax

The syntax for Merger files is line-based. All lines starting with `#`
are comments and ignored by any parser.

A line starting with a `C` denotes server input wires. The wires are
given in the format `[ START END ]` where `START` is the smallest wire
number in the range and `END` is the last wire number:

```
C [ 0 295 ]
```

Server input wires and output wires are provided in a similar fashion:

```
S [ 296 447 ]
...
outputs [ 856 887 ]
```

Sub-circuits are described in lines beginning with the C source file
path, a collection of input wire ranges for the function parameters
and an output wire range.

```
categorize_car.priv.c [ 0 39 ] out [ 448 463 ] [ 464 479 ]
```
