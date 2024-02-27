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

#pragma once

#include <cstdio>
#include <ctime>
#include <limits>
#include <vector>
#include <cstdint>

namespace SBVA {

struct Config {
    bool enable_trace = 0;
    bool generate_proof = 0;
    int64_t steps = std::numeric_limits<int64_t>::max();
    unsigned int max_replacements = 0;
    bool preserve_model_cnt = 0;
};

enum Tiebreak {
    ThreeHop, // default
    None, // use sorted order (should be equivalent to original BVA)
};

struct CNF {
    ~CNF();
    void run(Tiebreak t);

    void to_cnf(FILE*);
    std::vector<int> get_cnf(uint32_t& ret_num_vars, uint32_t& ret_num_cls);

    void to_proof(FILE*);

    // Read in CNF from file
    void parse_cnf(FILE* file, Config config);

    // This is how to add a CNF clause by clause
    void init_cnf(uint32_t num_vars, Config config);
    void add_cl(const std::vector<int>& cl_lits);
    void finish_cnf();

    void* data = nullptr;
};

const char* get_version_tag();
const char* get_version_sha1();
const char* get_compilation_env();

}
