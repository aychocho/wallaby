FROM nvidia/cuda:12.4.1-base-ubuntu22.04
COPY wallaby.so /home/wallaby/wallaby.so
ENV LD_PRELOAD=/home/wallaby/wallaby.so
