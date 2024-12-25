# cmake version
cmake_minimum_required(VERSION 3.31)

# define project name + used language
project(MDIO C) # ASM CXX

#set compiler
#find_program(CMAKE_C_COMPILER NAME avr-gcc PATH "/usr/bin/")
set(CMAKE_C_COMPILER "avr-gcc")
# collect .c files
file(GLOB ${PROJECT_NAME}_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

#for debugging 
 message(STATUS "${PROJECT_NAME}_SRC_FILES")
 message(STATUS "${CMAKE_C_COMPILER}")
 
# set include paths 
set(${PROJECT_NAME}_LIB_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/inc/)
set(STDLIB_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../STD_LIB/inc)

# collect .h files
file(GLOB ${PROJECT_NAME}LIB_INC_FILES ${MDIO_LIB_INC_PATH}*.h)
file(GLOB STDLIB_INC_FILES ${STDLIB_INC_PATH}*.h)
set(${PROJECT_NAME}_INC_FILES ${${PROJECT_NAME}LIB_INC_FILES} ${STDLIB_INC_FILES})

# specify include dir
include_directories(
    ${${PROJECT_NAME}_LIB_INC_PATH}
    ${STDLIB_INC_PATH}
)

# create static library
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC_FILES} ${${PROJECT_NAME}_INC_FILES})

# specify header access method for anyone wanting to link to this lib
target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_LIB_INC_PATH})
target_include_directories(${PROJECT_NAME} PUBLIC ${STDLIB_INC_PATH})