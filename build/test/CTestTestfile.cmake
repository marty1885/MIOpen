# CMake generated Testfile for 
# Source directory: /home/marty/Documents/MIOpen/test
# Build directory: /home/marty/Documents/MIOpen/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_main "/home/marty/Documents/MIOpen/build/bin/test_main")
set_tests_properties(test_main PROPERTIES  FAIL_REGULAR_EXPRESSION "FAILED")
