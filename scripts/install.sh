#! /bin/bash

if [ ! -d ${CF_SDL2} ]; then
    echo -e "\e[1mCompiling SDL2...\e[0m"
    mkdir -pv ${CF_SDL2}

    wget https://www.libsdl.org/release/SDL2-2.0.4.tar.gz
    tar -xf SDL2-2.0.4.tar.gz

    mkdir -pv SDL2-2.0.4/build

    cd SDL2-2.0.4/build
    cmake -DCMAKE_INSTALL_PREFIX=${CF_SDL2} ../
    make -j2 && make install
    cd ../..
else
    echo -e "\e[1mFound in cache: SDL2\e[0m"
fi

if [ ! -d ${CF_SDL2_IMAGE} ]; then
    echo -e "\e[1mCompiling SDL2 image...\e[0m"
    mkdir -pv ${CF_SDL2_IMAGE}

    wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.1.tar.gz
    tar -xf SDL2_image-2.0.1.tar.gz 

    cd SDL2_image-2.0.1
    ./configure --prefix=${CF_SDL2_IMAGE} --with-sdl-prefix=${CF_SDL2}
    make -j2 && make install
    cd ../
else
    echo -e "\e[1mFound in cache: SDL2 image\e[0m"
fi

if [ ! -d ${CF_GOOGLETEST} ]; then
    echo -e "\e[1mCompiling googletest...\e[0m"
    mkdir -pv ${CF_GOOGLETEST}

    git clone https://github.com/google/googletest.git

    mkdir -pv googletest/build

    cd googletest/build
    cmake -DCMAKE_INSTALL_PREFIX=${CF_GOOGLETEST} ../
    make -j2 && make install
    cd ../..
else
    echo -e "\e[1mFound in cache: googletest\e[0m"
fi
