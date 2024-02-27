/******************************************
Copyright (C) 2023 Andrew Haberlandt, Harrison Green, Marijn J.H. Heule

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
***********************************************/

#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include "sbva.h"

using namespace SBVA;

void run_bva(FILE *fin, FILE *fout, FILE *fproof, Tiebreak tiebreak, Config common) {
    CNF f;
    f.parse_cnf(fin, common);
    f.run(tiebreak);
    f.to_cnf(fout);
    if (fproof != nullptr) f.to_proof(fproof);
}

int main(int argc, char **argv) {

    FILE *fin = stdin;
    FILE *fout = stdout;
    FILE *fproof = nullptr;
    Tiebreak tiebreak = Tiebreak::ThreeHop;
    Config config;

    int opt;
    while ((opt = getopt(argc, argv, "p:i:o:t:s:vnc")) != -1) {
        switch (opt) {
            case 'i':
                fin = fopen(optarg, "r");
                if (fin == nullptr) {
                    fprintf(stderr, "Error: Could not open file %s for reading\n", optarg);
                    return 1;
                }
                break;
            case 'o':
                fout = fopen(optarg, "w");
                if (fout == nullptr) {
                    fprintf(stderr, "Error: Could not open file %s for writing\n", optarg);
                    return 1;
                }
                break;
            case 'p':
                config.generate_proof = true;
                fproof = fopen(optarg, "w");
                if (fin == nullptr) {
                    fprintf(stderr, "Error: Could not open file %s for reading\n", optarg);
                    return 1;
                }
                break;
            case 't':
                config.end_time = time(nullptr) + std::atoi(optarg);
                break;
            case 's':
                config.max_replacements = atoi(optarg);
                break;
            case 'v':
                config.enable_trace = true;
                break;
            case 'n':
                tiebreak = Tiebreak::None;
                break;
           case 'c':
                config.preserve_model_cnt = true;
                break;
            default:
                fprintf(stderr, "Usage: %s [-i input] [-o output]\n", argv[0]);
                return 1;
        }
    }

    run_bva(fin, fout, fproof, tiebreak, common);
}
