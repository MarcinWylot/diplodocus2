CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(diplodocus2)

add_executable(diplodocus2 src/diplodocus.cpp src/API.cpp src/BTCprov.cpp src/DBP.cpp src/Client.cpp src/Conductor.cpp src/ConductorNode.cpp src/Functions.cpp src/KeyManager2.cpp src/LUBM.cpp src/Molecules.cpp src/PageManager.cpp src/Partitioner.cpp src/TemplateManager.cpp src/TypesHierarchy.cpp src/TypesManager.cpp )

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -ggdb")

install(TARGETS diplodocus2 RUNTIME DESTINATION bin)
