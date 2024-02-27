# SBVA (Structured Bounded Variable Addition)

SBVA is a tool for reducing SAT formulas using _structured bounded variable addition_.

Read our SAT'23 paper: [Effective Auxiliary Variables via Structured
Reencoding](https://arxiv.org/pdf/2307.01904.pdf) (preprint)

🏆 SBVA-CaDiCaL (CaDiCaL w/ SBVA as preprocessor) was the overall main-track
winner of the [2023 SAT competition](https://satcompetition.github.io/2023/)!
(1st overall, 1st satisfiable, 2nd unsatisfiable)

## Build

```
mkdir build
cd build
cmake ..
make
```

## Usage

### As a preprocessor

```
./sbva [-i input] [-o output] [-p proof] [-t timeout] [-s max_replacements] [-v] [-n]
```

Options:
* `-i`: specify input file (default is stdin)
* `-o`: specify output file (default is stdout)
* `-p`: if specified, save a DRAT proof of the transformation to this file
* `-w`: if specified, the BVA algorithm will exit after this many steps
* `-s`: if specified, limits the number of replacements / new auxiliary variables
* `-v`: enable verbose logging
* `-n`: disable heuristic tiebreaking (breaks ties using variable order)

Examples:

```sh
# Reduce a formula
./sbva -i problem.cnf -o out.cnf

# Reduce a formula and generate a proof
./sbva -i problem.cnf -o out.cnf -p proof.drat
```

## Authors

SBVA was developed by Andrew Haberlandt and Harrison Green with advice from Marijn Heule.
