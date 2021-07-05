#!/bin/bash
BASE_DIR=$(dirname "$0")
BASE_DIR="$PWD/$BASE_DIR"
DEFAULT_BUILD_DIR="build"
DEFAULT_UTEST=1
DEFAULT_CORES=4

WHITE='\033[0;37m'
NO_COLOR='\033[0m'

echo -e "${WHITE}----------------- Hoopoe builder -----------------${NO_COLOR}"

read -p "What directory would you like to use for the build? [default: $DEFAULT_BUILD_DIR]: " BUILD_DIR
BUILD_DIR=${BUILD_DIR:-$DEFAULT_BUILD_DIR}
BUILD_DIR="$BASE_DIR/$BUILD_DIR"

read -p "Want to compile unit-tests? [Y/n]: " yn
case $yn in
    [Yy]* ) UTEST=1;;
    [Nn]* ) UTEST=0;;
    * ) UTEST=$DEFAULT_UTEST;;
esac

read -p "How many cores do you want to use for building? [default: $DEFAULT_CORES]: " CORES
CORES=${CORES:-$DEFAULT_CORES}

if [ ! -d $BUILD_DIR ]; then
    sudo -u ${USERNAME} mkdir $BUILD_DIR
fi

if [ "$UTEST" = "1" ]; then
    echo -e "${WHITE}-------------- Unpacking resources ---------------${NO_COLOR}"

    if [ -f "$BASE_DIR/Engine/Core/test/resources/res.zip" ]; then
        cd "$BASE_DIR/Engine/Core/test/resources/"
        sudo -u ${USERNAME} unzip res.zip
        rm res.zip
        cd $BASE_DIR
    fi

    if [ "$1" = "update-tests" ]; then
        rm -rf "$BUILD_DIR/utests/resources"
    fi
fi

cd $BUILD_DIR

echo -e "${WHITE}--------------------- CMAKE ----------------------${NO_COLOR}"
cmake -DUTEST=$UTEST ..

echo -e "${WHITE}--------------------- MAKE -----------------------${NO_COLOR}"
make -j $CORES

echo -e "${WHITE}--------------- Building complete! ---------------${NO_COLOR}"