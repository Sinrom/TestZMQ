cmake_minimum_required(VERSION 3.0)

add_definitions("-Wno-deprecated-declarations")
add_definitions("-Wno-unused-parameter")
add_definitions("-Wno-unused-variable")
add_definitions("-Wno-unused-function")
add_definitions("-Wno-reorder")
add_definitions("-Wno-switch")
add_definitions("-Wno-conversion-null")
add_definitions("-Wno-sign-compare")

project(zmq_study)

add_subdirectory(pubsub)
add_subdirectory(pushpull)
add_subdirectory(repreq)
add_subdirectory(routerdealer)
add_subdirectory(xpubxsub)

set(CMAKE_INSTALL_PREFIX "~/bin/zmq_study")
