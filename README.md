# wallaby

**wallaby** is a tool built to expose a core vulnerability in decentralized compute networks: They have no control over the hardware. **wallaby** misrepresents the name of any GPU on any hardware.

Compile wallaby by running the following command:

    gcc -shared -fPIC -o wallaby.so wallaby.c -ldl

Run wallaby as follows:

    LD_PRELOAD=./wallaby.so nvidia-smi

To get wallaby to hide itself and run anytime nvidia-smi is called, add the following line to the end of the .bashrc

    export LD_PRELOAD={PATH_TO_WALLABY}/wallaby.so:$LD_PRELOAD
