# wallaby

**wallaby** is a tool built to expose a core vulnerability in decentralized compute networks: They have no control over the hardware. **wallaby** misrepresents the name of any GPU on any hardware.

Compile wallaby by running the following command:

    gcc -shared -fPIC -o wallaby.so wallaby.c -ldl


#Local environments


Preload wallaby as follows:

    LD_PRELOAD=./wallaby.so nvidia-smi

To get wallaby to hide itself and run anytime nvidia-smi is called, add the following line to the end of the .bashrc

    export LD_PRELOAD={PATH_TO_WALLABY}/wallaby.so:$LD_PRELOAD

To dynamically add and remove wallaby, add the following aliases to the .bashrc

    #add wallaby alias
    alias wallaby='echo "export LD_PRELOAD={PATH_TO_WALLABY}/wallaby.so:\$LD_PRELOAD" >> ~/.bashrc && newbash'
    #remove wallaby alias
    alias killWallaby='sed -i "\#^export LD_PRELOAD={PATH_TO_WALLABY}/wallaby.so.*\$#d" ~/.bashrc && unset LD_PRELOAD && echo "we wallaby huntin" && newbash'


#Docker environments

Build the docker image (replace the name with the container to spoof):

    docker build -t nvidia/cuda:12.4.1-base-ubuntu22.04 .

Run the docker image

    sudo docker run --runtime=nvidia -it nvidia/cuda:12.4.1-base-ubuntu22.04 bash
