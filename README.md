# SBVA (Structured Bounded Variable Addition)

SBVA is a tool for reducing SAT formulas using _structured bounded variable
addition_. Read the SAT'23 paper: [Effective Auxiliary Variables via Structured
Reencoding](https://arxiv.org/pdf/2307.01904.pdf) (preprint)

This a version of the [original code](https://github.com/hgarrereyn/SBVA) that
has a few improvements, notably it can be used as a library, and has a
deterministic timeout via steps. It also has a manual page, and has better help.

## Build

```
git clone https://github.com/meelgroup/SBVA
mkdir build && cd build
cmake ..
make -j8
sudo make install
```

## Usage

```shell
$ ./sbva -s 20 mizh-md5-47-3.cnf simplified.cnf
c SBVA Version: 23b96710558480e04bb30289bc40f0ef46483abf
c executed with command line: ./sbva -s 20 mizh-md5-47-3.cnf simplified.cnf
c reading CNF from file mizh-md5-47-3.cnf
c writing transformed CNF to file simplified.cnf
c SBVA Finished. Num vars now: 65635 num cls: 273366
c steps remainK: -93.31 Timeout: Yes T: 1.79
```

```shell
Usage: sbva [options] input output

Positional arguments:
  files                input file and output file [nargs: 0 or more]

Optional arguments:
  -h, --help           shows help message and exits
  -v, --version        prints version information and exits
  -v, --verb           Enable tracing [default: 0]
  -p, --proof          Emit proof file here
  -s, --steps          Number of computation steps to do [default: 9223372036854775807]
  -m, --maxreplace     Maximum number of replacements to do. 0 = no limit [default: 0]
  -n, --normal         Use original BVA tie-break. Runs BVA instead of SBV
  -c, --countpreserve  Preserve model count. Adds additional clauses but
                       allows the tool to be used in propositional model
```

## Authors

SBVA was developed by Andrew Haberlandt and Harrison Green with advice from Marijn Heule.

This version of SBVA has been messed around by Mate Soos
