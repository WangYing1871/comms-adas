set(main_src main.cpp)
set (bin_name "main")
add_executable(${bin_name} ${main_src})
target_include_directories(${bin_name} PUBLIC /home/wangying/software/boost_1_84_0-build/include/boost-1_84)        
target_include_directories(${bin_name} PUBLIC /home/wangying/software/comms-build/include)        
target_include_directories(${bin_name} PUBLIC "${PROJECT_SOURCE_DIR}/adas/adas/include")

