#cmake version
cmake_minimum_required(VERSION 3.12.0)

#project name: main
project(challenge)

set(EXECUTABLE_OUTPUT_PATH "bin")

#get all files in current dirctory
aux_source_directory(. DIR_SRCS)

#compile main.cpp to challenge (an executble file)
add_executable(challenge ${DIR_SRCS})

# make test
enable_testing()

macro (do_test arg1 arg2 result)
  add_test (NAME test_${arg1}_${arg2} COMMAND challenge ${arg1} ${arg2} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test ("abcde" 2 "ba\\ndc\\n e\\n$")
do_test ("abcde" 3 "cba\\n ed\\n$")
do_test ("abcde" 4 "dcba\\n   e\\n$")
do_test ("abcde" 5 "edcba\\n$")
do_test ("abcde" 6 " edcba\\n$")