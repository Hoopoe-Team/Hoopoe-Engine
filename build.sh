#!/bin/bash
DEFAULT_BUILD_DIR="build"
DEFAULT_UTEST=1
DEFAULT_CORES=6

WHITE='\033[0;37m'
NO_COLOR='\033[0m'

echo -e "${WHITE}----------------- Hoopoe builder -----------------${NO_COLOR}"

read -p "What directory would you like to use for the build? [default: $DEFAULT_BUILD_DIR]: " BUILD_DIR
BUILD_DIR=${BUILD_DIR:-$DEFAULT_BUILD_DIR}

read -p "Want to compile unit-tests? [Y/n]: " yn
case $yn in
    [Yy]* ) UTEST=1;;
    [Nn]* ) UTEST=0;;
    * ) UTEST=$DEFAULT_UTEST;;
esac

read -p "How many cores do you want to use for building? [default: $DEFAULT_CORES]: " CORES
CORES=${CORES:-$DEFAULT_CORES}

if [ ! -d $BUILD_DIR ]; then
    mkdir $BUILD_DIR
fi

if [ "$UTEST" = "1" ]; then
    cd "Engine/Core/test/resources/"
    echo -e "${WHITE}-------------- Unpacking resources ---------------${NO_COLOR}"
    
    if [ ! -d "res" ]; then
        sudo -u ${USERNAME} mkdir res
    fi

    sudo -u ${USERNAME} unzip res.zip

    cd "../../../../"
fi

cd $BUILD_DIR
echo -e "${WHITE}--------------------- CMAKE ----------------------${NO_COLOR}"
cmake -DUTEST=$UTEST ..

echo -e "${WHITE}--------------------- MAKE -----------------------${NO_COLOR}"
make -j $CORES

echo -e "${WHITE}--------------- Building complete! ---------------${NO_COLOR}"