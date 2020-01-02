#!/usr/bin/env sh

# this script builds the project and 
#   put the results in "cppTraining/build" folder
# usage : 
#   user@mnling:> ./buildRun.sh

localFolder=$(pwd | sed -e 's/\(.*\)\/cppTraining.*/\1/')
projFolder="${localFolder}/cppTraining"
srcFolder="${projFolder}/src"
inputFilesFolder="${srcFolder}/sample_input_files"
buildFolder="${projFolder}/build"

termString="$(whoami)@$(hostname -s):$"

echo "$termString cd ${projFolder}"
cd ${projFolder}
echo "$termString ./scripts/build.sh"
./scripts/build.sh

exeFile="${buildFolder}/cpptrain"
testCaseName="100MHZ_2rb_1ant_1mcs"
#testCaseName="100MHZ_2rb_1ant_1mcs_no_interleave"

expOutputFileName="${testCaseName}_exp_out.txt"
outputFileName="${testCaseName}_out.txt"

ls ${exeFile}

if [ -f "${exeFile}" ]; then
    echo "build sucessful, run dummy test"
    echo "${termString} " ${exeFile}
    ${exeFile}
  
    #echo "compare output with expected output"
    #echo "${termString} cd ${inputFilesFolder}"
    #cd "${inputFilesFolder}"

    #echo "${termString} diff ${expOutputFileName} ${outputFileName}"
    #diff ${expOutputFileName} ${outputFileName} && echo "TEST PASSED" || echo "TEST FAILED : output file != expected output file"

else
    echo "build FAILED"
fi


