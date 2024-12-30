# wallaby
Spoofs nvidia-smi

Compile wallaby by running the following command

gcc -shared -fPIC -o wallaby.so wallaby.c -ldl

Run wallaby as follows: 

LD_PRELOAD=./wallaby.so nvidia-smi
