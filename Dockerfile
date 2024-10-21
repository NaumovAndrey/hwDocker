FROM ubuntu:20.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    && apt-get clean

# C++20
RUN apt-get install -y software-properties-common \
    && add-apt-repository ppa:ubuntu-toolchain-r/test \
    && apt-get update \
    && apt-get install -y gcc-10 g++-10 \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 100

RUN apt-get install -y cmake

WORKDIR /app

COPY ./src /app/src
COPY ./include /app/include
COPY ./CMakeLists.txt /app/

ENV CC=gcc-10
ENV CXX=g++-10

RUN mkdir build && cd build && \
    cmake .. -DCMAKE_CXX_STANDARD=20 && \
    make

CMD ["./build/proga"]