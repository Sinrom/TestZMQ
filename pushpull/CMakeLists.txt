project(pushpull)

add_definitions("-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
#include_directories()

#file(GLOB PUSHPULL_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_executable(push push.cpp)
target_link_libraries(push zmq)
install (TARGETS push DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)

add_executable(pull pull.cpp)
target_link_libraries(pull zmq)
install (TARGETS pull DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)
