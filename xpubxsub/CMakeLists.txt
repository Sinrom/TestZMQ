project(xpubxsub)

add_definitions("-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
#include_directories()

#file(GLOB XPUBXSUB_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_executable(xproxy xproxy.cpp)
target_link_libraries(xproxy zmq)
install (TARGETS xproxy DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)

add_executable(xpub pub.cpp)
target_link_libraries(xpub zmq)
install (TARGETS xpub DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)

add_executable(xsub sub.cpp)
target_link_libraries(xsub zmq)
install (TARGETS xsub DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)
