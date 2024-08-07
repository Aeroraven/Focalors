cmake_minimum_required(VERSION 3.10)
project(Anthem)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fsanitize=address")


file(GLOB SOURCE_STAGES "problems-cpp/*.cpp")
file(GLOB SOURCE_STAGES_TMPL "templates-cpp/*.cpp")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

foreach( SRC_FILE_NAME ${SOURCE_STAGES} )
    get_filename_component( SRC_FILE_NAME_SHORT ${SRC_FILE_NAME} NAME_WE )
    add_executable( ${SRC_FILE_NAME_SHORT} ${SRC_FILE_NAME} )
endforeach( SRC_FILE_NAME ${SOURCE_STAGES} )

foreach( SRC_FILE_NAME_TMPL ${SOURCE_STAGES_TMPL} )
    get_filename_component( SRC_FILE_NAME_SHORT_TMPL ${SRC_FILE_NAME_TMPL} NAME_WE )
    add_executable( ${SRC_FILE_NAME_SHORT_TMPL} ${SRC_FILE_NAME_TMPL}  )
endforeach( SRC_FILE_NAME_TMPL ${SOURCE_STAGES_TMPL} )

add_executable(rdgen "misc/rdgen.cpp")
#add_executable(rdgen "misc/demo.cpp")