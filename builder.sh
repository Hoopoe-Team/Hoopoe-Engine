#!/bin/bash

# ----------------------------------------- #
# -------------- Functions ---------------- #
# ----------------------------------------- #

function he_valid_command() {
    RESULT=$?
    if [ $RESULT -eq 1 ]; then
        exit -1
    fi
}

# he_set_option
# $1 - message to display                  
# $2 - default value                       
# $3 - sym-link   
function he_set_option() {
    var_link=$3

    read -p "$1 [default: $2]: " $3
    eval $var_link=\${$var_link:-$2\}
}

# he_set_optionYN - set
# $1 - message to display                  
# $2 - default value                       
# $3 - sym-link                             
function he_set_optionYN() {
    var_link=$3

    echo -n $1 
    if [ "$2" = "1" ]; then
        echo -n " [Y/n]: "
    else
        echo -n " [y/N]: "
    fi

    read yn
    case $yn in
        [Yy]* ) eval $var_link=1;;
        [Nn]* ) eval $var_link=0;;
        * ) eval $var_link=$2;;
    esac
}

# ----------------------------------------- #
# ---------- Creating variables ----------- #
# ----------------------------------------- #

BASE_DIR=$(dirname "$0")
BASE_DIR="$PWD/$BASE_DIR"

RESOURCE_NAME="res.zip"
CONFIG_PATH="builder.config"
RESOURCE_LIST_PATH="builder-resources.list"
DEPENDENCIES_LIST_PATH="builder-dependencies.list"

DEFAULT_BUILD_DIR="build"
DEFAULT_UTEST=1
DEFAULT_CORES=4

ENGINE_ONLY=0
SANDBOX_ONLY=0
UPDATE_TESTS=0
DEFAULT_SETTINS=0
PACK_RESOURCES=0

source $CONFIG_PATH

WHITE='\033[0;37m'
RED='\033[0;31m'
NO_COLOR='\033[0m'

ENGINE_ZIP_RESOURCES=()
BUILDER_DEPENDENCIES=()

mapfile ENGINE_ZIP_RESOURCES < $RESOURCE_LIST_PATH; he_valid_command
mapfile BUILDER_DEPENDENCIES < $DEPENDENCIES_LIST_PATH; he_valid_command

HELP_MSG="\
Available options:\n\
\t${WHITE}--engine${NO_COLOR} or ${WHITE}-e${NO_COLOR} \t\tbuild engine only.\n\
\t${WHITE}--sandbox${NO_COLOR} or ${WHITE}-s${NO_COLOR} \tbuild sandbox only.\n\
\t${WHITE}--update-tests${NO_COLOR} or ${WHITE}-u${NO_COLOR} \tupdate UTest resources.\n\
\t${WHITE}--pack-resources${NO_COLOR} or ${WHITE}-p${NO_COLOR} \tpack the resources in the zip archives.\n\
\t${WHITE}--default${NO_COLOR} or ${WHITE}-d${NO_COLOR} \tcompile with default settings.\
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
        "--pack-resources" | "-p" )
            PACK_RESOURCES=1
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

# ----------------------------------------- #
# ------- Dependencies verification ------- #
# ----------------------------------------- #

echo -e "${WHITE}----------- Dependencies verification ------------${NO_COLOR}"


DEPENDENCE_FLAG=0
for current_dependence in "${BUILDER_DEPENDENCIES[@]}"
do
    if ! command -v $current_dependence &> /dev/null; then
        DEPENDENCE_FLAG=1
        echo -e -n "${RED}Missing dependency: ${current_dependence}${NO_COLOR}"
    fi
done

if [ "$DEPENDENCE_FLAG" = "1" ]; then
    echo ""
    exit -1
fi

if [ ! "$PACK_RESOURCES" = "1" ]; then
    if [ ! "$DEFAULT_SETTINS" = "1" ]; then
        echo -e "${WHITE}----------- Setting the build options ------------${NO_COLOR}"

        # ----------------------------------------- #
        # ----------- Default build dir ----------- #
        # ----------------------------------------- #

        he_set_option "What directory would you like to use for the build?" $DEFAULT_BUILD_DIR "BUILD_DIR"

        if [ ! "$BUILD_DIR" = "$DEFAULT_BUILD_DIR" ]; then
            sed -i "s/^\(DEFAULT_BUILD_DIR\s*=\s*\).*\$/\1$BUILD_DIR/" $CONFIG_PATH
        fi

        # ----------------------------------------- #
        # ----------------- UTests ---------------- #
        # ----------------------------------------- #

        if [ ! "$SANDBOX_ONLY" = "1" ]; then
            he_set_optionYN "Want to compile unit-tests?" $DEFAULT_UTEST "UTEST"

            if [ ! "$UTEST" = "$DEFAULT_UTEST" ]; then
                sed -i "s/^\(DEFAULT_UTEST\s*=\s*\).*\$/\1$UTEST/" $CONFIG_PATH
            fi
        fi
        # ----------------------------------------- #
        # ------- Number of cores for build ------- #
        # ----------------------------------------- #

        he_set_option "How many cores do you want to use for building?" $DEFAULT_CORES "CORES"

        if [ ! "$CORES" = "$DEFAULT_CORES" ]; then
            sed -i "s/^\(DEFAULT_CORES\s*=\s*\).*\$/\1$CORES/" $CONFIG_PATH
        fi
    else
        BUILD_DIR="$BASE_DIR/$DEFAULT_BUILD_DIR"
        UTEST=$DEFAULT_UTEST
        CORES=$DEFAULT_CORES
    fi

    if [ ! -d $BUILD_DIR ]; then
        mkdir $BUILD_DIR; he_valid_command
    fi

    # ----------------------------------------- #
    # --------- Resources for utests ---------- #
    # ----------------------------------------- #

    if [ "$UTEST" = "1" ] && [ ! "$SANDBOX_ONLY" = "1" ]; then
        echo -e "${WHITE}-------------- Unpacking resources ---------------${NO_COLOR}"

        for current_resource in "${ENGINE_ZIP_RESOURCES[@]}"
        do
            if [ -f "$BASE_DIR/$current_resource/$RESOURCE_NAME" ]; then
                cd "$BASE_DIR/$current_resource"; he_valid_command
                unzip $RESOURCE_NAME; he_valid_command
                rm $RESOURCE_NAME
                cd $BASE_DIR; he_valid_command
            fi
        done

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
else
    # ----------------------------------------- #
    # ------------ Pack resources  ------------ #
    # ----------------------------------------- #

    for current_resource in "${ENGINE_ZIP_RESOURCES[@]}"
    do
        # very dangerous
        if [ ! -f "$BASE_DIR/$current_resource/$RESOURCE_NAME" ]; then
            cd "$BASE_DIR/$current_resource"; he_valid_command
            zip -r $RESOURCE_NAME */; he_valid_command
            rm -r */ 
            cd $BASE_DIR; he_valid_command
            echo -e "${WHITE}----------------- Pack complete! -----------------${NO_COLOR}"
        else
            echo -e "${WHITE}Resource $BASE_DIR/$current_resource/$RESOURCE_NAME is already is packed.${NO_COLOR}"
            echo -e "${WHITE}---------------- Pack incomplete! ----------------${NO_COLOR}"
        fi
    done
fi