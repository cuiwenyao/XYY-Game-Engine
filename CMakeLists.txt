# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.20)

# 项目信息
project(XYY_Game_Engine)

#设置 PROJECT_SOURCE_DIR
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
#设置 install 目录前缀
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})


#设置第三方库引用目录
set(THIRD_PART_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/contrib/include)
#设置第三方lib目录
set(THIRD_PART_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/contrib/lib)

INCLUDE_DIRECTORIES(${THIRD_PART_INCLUDE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/code)

LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} main.cpp)

#target_link_libraries(${PROJECT_NAME} XYY_Game_Engine)

#添加子目录
add_subdirectory(code)


#install
INSTALL(FILES dev.md readme.md DESTINATION doc/)
#安装库文件
install(TARGETS XYY_Game_Engine DESTINATION ${PROJECT_SOURCE_DIR}/lib)
#安装测试用的文件
#INSTALL(FILES )