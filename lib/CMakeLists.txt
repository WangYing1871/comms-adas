set(server_name server)
set(server_src 
    src/session.cpp
    src/server_session.cpp
    src/tcp_server.cpp
    src/tcp_server_main.cpp
   )
add_executable(${server_name} ${server_src})
target_include_directories(${server_name} PUBLIC /home/wangying/software/boost_1_84_0-build/include/boost-1_84)        
target_include_directories(${server_name} PUBLIC /home/wangying/software/comms-build/include)        
target_include_directories(${server_name} PUBLIC "${PROJECT_SOURCE_DIR}/adas/adas/include")
target_include_directories(${server_name} PUBLIC "${PROJECT_SOURCE_DIR}/lib/include")

set(client_name client)
set(client_src 
    src/session.cpp
    src/client_session.cpp
    src/tcp_client.cpp
    src/tcp_client_main.cpp
   )
add_executable(${client_name} ${client_src})
target_include_directories(${client_name} PUBLIC /home/wangying/software/boost_1_84_0-build/include/boost-1_84)        
target_include_directories(${client_name} PUBLIC /home/wangying/software/comms-build/include)        
target_include_directories(${client_name} PUBLIC "${PROJECT_SOURCE_DIR}/adas/adas/include")
target_include_directories(${client_name} PUBLIC "${PROJECT_SOURCE_DIR}/lib/include")
