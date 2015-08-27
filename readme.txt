To run 32 bit code and generate .o file
nasm -f elf32 32_bit.asm
gcc -m32 32_bit.o -o 32_bit_run
./32_bit_run

To run 64 bit code and generate .o file
nasm -f elf64 64_bit.asm
ld 64_bit.o -o 64_bit_run
./64_bit_run 

Translator file 
g++ translator.cpp 
./a.out 


Run the created file
nasm -f elf64 64_bit_conv.asm 
ld 64_bit.o -o 64_bit_conv_run 
./64_bit_conv_run 

