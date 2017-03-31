project(pubsub)

add_definitions("-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
#include_directories()

#file(GLOB PUBSUB_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_executable(pub pub.cpp)
target_link_libraries(pub zmq)
install (TARGETS pub DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)

add_executable(sub sub.cpp)
target_link_libraries(sub zmq)
install (TARGETS sub DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)
