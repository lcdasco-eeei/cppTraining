#!/usr/bin/env sh

# this script builds the project and 
#   put the results in "cppTraining/build" folder
# usage : 
#   user@mnling:> ./build.sh

localFolder=$(pwd | sed -e 's/\(.*\)\/cppTraining.*/\1/')
projFolder="${localFolder}/cppTraining"
srcFolder="${projFolder}/src"
buildFolder="${projFolder}/build"

echo "building files from ${srcFolder}"

if [ -d ${buildFolder} ]
then
    echo "clean existing build folder"
    echo "rm -rf ${buildFolder}"
    rm -rf ${buildFolder}
fi

mkdir ${buildFolder}
cd ${buildFolder}


datePref=$(date +%d%m_%H%M)
buildLog="build_${dataPref}.log"

#cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake ${srcFolder}

# build
make
