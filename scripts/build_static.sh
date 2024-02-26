rm -rf CMake* src cmake* Make* sbva*
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DSTATICCOMPILE=ON ..
make -j8
