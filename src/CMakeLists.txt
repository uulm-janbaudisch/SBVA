# Copyright (c) 2017, Mate Soos
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/eigen-3.4.0/)

if (NOT WIN32)
    add_cxx_flag_if_supported("-Wno-bitfield-constant-conversion")
    #add_cxx_flag_if_supported("-Wduplicated-cond")
    #add_cxx_flag_if_supported("-Wduplicated-branches")
    add_cxx_flag_if_supported("-Wlogical-op")
    add_cxx_flag_if_supported("-Wrestrict")
    add_cxx_flag_if_supported("-Wnull-dereference")
    add_cxx_flag_if_supported("-Wdouble-promotion")
    add_cxx_flag_if_supported("-Wshadow")
    add_cxx_flag_if_supported("-Wformat=2")
    add_cxx_flag_if_supported("-Wextra-semi")
    add_cxx_flag_if_supported("-pedantic")
    #add_cxx_flag_if_supported("-Wdeprecated")
endif()

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/GitSHA1.cpp.in"
  "${CMAKE_CURRENT_BINARY_DIR}/GitSHA1.cpp" @ONLY)

SET(SOURCES
    sbva.cc
    ${CMAKE_CURRENT_BINARY_DIR}/GitSHA1.cpp)

ADD_LIBRARY(sbva ${SOURCES} ${LIB})
target_link_libraries (sbva)

set_target_properties(sbva PROPERTIES
    PUBLIC_HEADER "${sbva_public_headers}"
    VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
    INSTALL_RPATH_USE_LINK_PATH TRUE
)

# add_executable (sbva-bin main.cpp)

# set(sbva_exec_link_libs sbva)

# IF (ZLIB_FOUND)
#     SET(sbva_exec_link_libs ${sbva_exec_link_libs} ${ZLIB_LIBRARY})
# ENDIF()

# target_link_libraries(sbva-bin ${sbva_exec_link_libs})

# if (NOT WIN32)
#     set_target_properties(sbva-bin PROPERTIES
#     OUTPUT_NAME sbva
#     RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
#     INSTALL_RPATH_USE_LINK_PATH TRUE)
# else()
#     set_target_properties(sbva-bin PROPERTIES
#     OUTPUT_NAME sbva-win
#     RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
#     INSTALL_RPATH_USE_LINK_PATH TRUE)
# endif()
