cmake_minimum_required(VERSION 2.8)

project(sproto)
include_directories(lua5.2/src)
link_directories(${CMAKE_SOURCE_DIR})

set(LIB_SRC 
	sproto/sproto.c
	sproto/sproto.h
	sproto/lsproto.c
)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2")
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
#add_library(sproto SHARED ${LIB_SRC})
#target_link_libraries(sproto lua.lib)

project(cppsproto)
set(LIB_SRC 
	sproto/sproto.c
	sproto/sproto.h	
	cppsproto.cpp 
	SMessage.cpp
	cppsproto.h 
	SMessage.h
)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O2")
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
add_library(cppsproto SHARED ${LIB_SRC})

project(test)
link_directories(${CMAKE_SOURCE_DIR}/lib)
set(EXE_SRC demo.cpp addressbookmessage.cpp)
#set(CMAKE_CXX_FLAGS "-Wall -g -O2")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
add_executable(demo ${EXE_SRC})
target_link_libraries(demo cppsproto)


add_library(bit32 SHARED lbitlib.c )
target_link_libraries(bit32 liblua)


add_subdirectory(lua5.2)

add_subdirectory(lpeg)
#target_link_libraries(lpeg liblua)
