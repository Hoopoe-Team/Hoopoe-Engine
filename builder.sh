#!/bin/bash
BASE_DIR=$(dirname "$0")
BASE_DIR="$PWD/$BASE_DIR"

CONFIG_PATH="builder.config"

DEFAULT_BUILD_DIR="build"
DEFAULT_UTEST=1
DEFAULT_CORES=4

source $CONFIG_PATH

ENGINE_ONLY=0
SANDBOX_ONLY=0
UPDATE_TESTS=0
DEFAULT_SETTINS=0
CLEAN=0

WHITE='\033[0;37m'
RED='\033[0;31m'
NO_COLOR='\033[0m'

HELP_MSG="\
Available options:\n\
\t${WHITE}--engine${NO_COLOR} or ${WHITE}-e${NO_COLOR} \t\tbuild engine only.\n\
\t${WHITE}--sandbox${NO_COLOR} or ${WHITE}-s${NO_COLOR} \tbuild sandbox only.\n\
\t${WHITE}--update-tests${NO_COLOR} or ${WHITE}-u${NO_COLOR} \tupdate UTest resources.\n\
\t${WHITE}--default${NO_COLOR} or ${WHITE}-d${NO_COLOR} \tcompile with default settings.\n\
"
# ----------------------------------------- #
# ---------- Processing argumets ---------- #
# ----------------------------------------- #

i=1;
for arg in "$@" 
do
    case $arg in
        "--engine" | "-e" )
            ENGINE_ONLY=1
            SANDBOX_ONLY=0
            ;;
        "--sandbox" | "-s" )
            ENGINE_ONLY=0
            SANDBOX_ONLY=1
            ;;
        "--update-tests" | "-u" )
            UPDATE_TESTS=1
            ;;
        "--default" | "-d" )
            DEFAULT_SETTINS=1
            ;;
        "--help" | "-h" )
            echo -e $HELP_MSG
            exit 0
            ;;
        * )
            echo -e "${RED}Unknown option: $arg${NO_COLOR}"
            echo -e $HELP_MSG
            exit -1
            ;;
    esac

    i=$((i + 1));
done

echo -e "${WHITE}----------------- Hoopoe builder -----------------${NO_COLOR}"

if [ ! "$DEFAULT_SETTINS" = "1" ]; then
    # ----------------------------------------- #
    # ----------- Default build dir ----------- #
    # ----------------------------------------- #

    read -p "What directory would you like to use for the build? [default: $DEFAULT_BUILD_DIR]: " BUILD_DIR
    BUILD_DIR=${BUILD_DIR:-$DEFAULT_BUILD_DIR}

    if [ ! "$BUILD_DIR" = "$DEFAULT_BUILD_DIR" ]; then
        sed -i "s/^\(DEFAULT_BUILD_DIR\s*=\s*\).*\$/\1$BUILD_DIR/" $CONFIG_PATH
    fi

    # ----------------------------------------- #
    # ----------------- UTests ---------------- #
    # ----------------------------------------- #

    if [ ! "$SANDBOX_ONLY" = "1" ]; then
        read -p "Want to compile unit-tests? [Y/n]: " yn
        case $yn in
            [Yy]* ) UTEST=1;;
            [Nn]* ) UTEST=0;;
            * ) UTEST=$DEFAULT_UTEST;;
        esac

        if [ ! "$UTEST" = "$DEFAULT_UTEST" ]; then
            sed -i "s/^\(DEFAULT_UTEST\s*=\s*\).*\$/\1$UTEST/" $CONFIG_PATH
        fi
    fi
    # ----------------------------------------- #
    # ------- Number of cores for build ------- #
    # ----------------------------------------- #

    read -p "How many cores do you want to use for building? [default: $DEFAULT_CORES]: " CORES
    CORES=${CORES:-$DEFAULT_CORES}

    if [ ! "$CORES" = "$DEFAULT_CORES" ]; then
        sed -i "s/^\(DEFAULT_CORES\s*=\s*\).*\$/\1$CORES/" $CONFIG_PATH
    fi
else
    BUILD_DIR="$BASE_DIR/$DEFAULT_BUILD_DIR"
    UTEST=$DEFAULT_UTEST
    CORES=$DEFAULT_CORES
fi

if [ ! -d $BUILD_DIR ]; then
    sudo -u ${USERNAME} mkdir $BUILD_DIR
fi

# ----------------------------------------- #
# --------- Resources for utests ---------- #
# ----------------------------------------- #

if [ "$UTEST" = "1" ] && [ ! "$SANDBOX_ONLY" = "1" ]; then
    echo -e "${WHITE}-------------- Unpacking resources ---------------${NO_COLOR}"

    if [ -f "$BASE_DIR/Engine/Core/test/resources/res.zip" ]; then
        cd "$BASE_DIR/Engine/Core/test/resources/"
        sudo -u ${USERNAME} unzip res.zip
        rm res.zip
        cd $BASE_DIR
    fi

    if [ "$UPDATE_TESTS" = "1" ] ; then
        rm -rf "$BUILD_DIR/../bin/utests/resources"

        if [ "$SANDBOX_ONLY" = "1" ]; then
            echo -e "${RED}Unable to update sandbox test resources.${NO_COLOR}"
        fi
    fi
fi

cd $BUILD_DIR

echo -e "${WHITE}--------------------- CMAKE ----------------------${NO_COLOR}"

if [ -f "$BUILD_DIR/CMakeCache.txt" ]; then
    rm -rf "$BUILD_DIR/CMakeCache.txt"
fi

if [ "$ENGINE_ONLY" = "1" ]; then
    cmake -DUTEST=$UTEST "$BASE_DIR/Engine/"
elif [ "$SANDBOX_ONLY" = "1" ]; then
    cmake -DSANDBOX_ONLY=1 "$BASE_DIR/Sandbox/"
else
    cmake -DUTEST=$UTEST ..
fi

echo -e "${WHITE}--------------------- MAKE -----------------------${NO_COLOR}"
make -j $CORES

echo -e "${WHITE}--------------- Building complete! ---------------${NO_COLOR}"