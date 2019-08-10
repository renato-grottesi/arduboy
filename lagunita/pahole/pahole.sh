#/bin/bash

# compiler objects with readable debug symbols
g++ --std=c++14 -c components.cpp -Ipahole -g -o components.o

# generate pahole report
pahole --show_private_classes components.o

# remove partial objects
rm components.o
