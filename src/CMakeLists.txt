cmake_minimum_required( VERSION 3.7 )

project(cpptrain LANGUAGES CXX C ASM)

set( DEFAULT_CMAKE_BUILD_TYPE "RelWithDebInfo" )
set( FORCE_CMAKE_BUILD_TYPE ${DEFAULT_CMAKE_BUILD_TYPE} )

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

# global compile options
add_compile_options("$<$<CONFIG:RelWithDebInfo>:-O3>")
add_compile_options("$<$<CONFIG:Release>:-O3>")
add_compile_options("-Wall")
add_compile_options("-Werror")
add_compile_options("-Wfatal-errors")
add_compile_options("-fno-strict-aliasing") # this optimization can be re-enabled once code is compliant

# add the executable
add_executable(${PROJECT_NAME} 
#    LdecController.cpp
	BasicSyntax.cpp
	DataTypes.cpp
    main.cpp
)

include_directories (
#  "../ext/cmodel/h"
)

#target_link_libraries(
#  ${PROJECT_NAME}
#  ${CMAKE_CURRENT_SOURCE_DIR}/../ext/cmodel/lib/libcnf95xxn_mhab.so
#  ${CMAKE_CURRENT_SOURCE_DIR}/../ext/cmodel/lib/libtc1800.so
#)

