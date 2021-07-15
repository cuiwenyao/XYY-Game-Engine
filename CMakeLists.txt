# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.20)

# 项目信息
project(XYY_Game_Engine)


#变量设置   主要是目录变量
#CMAKE_INSTALL_PREFIX
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR})
#code目录
set(CODE_ROOT_PATH ${CMAKE_CURRENT_LIST_DIR}/code/)
#build目录
set(BUILD_PATH ${CMAKE_CURRENT_LIST_DIR}/build/)
#存放生成的lib的目录
set(LIB_PATH ${BUILD_PATH}/../lib/)
#存放生成的dll的目录
set(DLL_PATH ${BUILD_PATH}/../dll/)
#编译所需包含目录
set(INCLUDE_PATH_CODE ${CMAKE_CURRENT_LIST_DIR}/include/)
set(INCLUDE_PATH_CONTRIB ${CMAKE_CURRENT_LIST_DIR}/contrib/include/)
#编译所需库目录
set(LIBRARY_PATH_CONTRIB ${CMAKE_CURRENT_LIST_DIR}/contrib/lib/)
#设置test路径
set(TEST_PATH ${CMAKE_CURRENT_LIST_DIR}/build/test/)
#指定程序的包含目录 库目录
#引用目录
INCLUDE_DIRECTORIES(${INCLUDE_PATH_CODE})
INCLUDE_DIRECTORIES(${INCLUDE_PATH_CONTRIB})
INCLUDE_DIRECTORIES(${TEST_PATH}/include)
#库目录 将生成的lib 目录也包含在内，为了给test使用
LINK_DIRECTORIES(${LIBRARY_PATH_CONTRIB})
LINK_DIRECTORIES(${LIB_PATH})

#设置目标的属性 
function(SetDefaultTargetProperties target)
	#程序生成文件的目录   
	set_target_properties(${target} PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${LIB_PATH}
		LIBRARY_OUTPUT_DIRECTORY ${LIB_PATH}
		RUNTIME_OUTPUT_DIRECTORY ${DLL_PATH}
	)
endfunction()

#MESSAGE(STATUS ${LIB_PATH})

#code的编译  得到 XYY_Game_Engine.lib XYY_Game_Engine.dll 
add_subdirectory(${CODE_ROOT_PATH})


#install
#INSTALL(TARGETS myrun mylib mystaticlib
#RUNTIME DESTINATION bin
#LIBRARY DESTINATION lib
#ARCHIVE DESTINATION libstatic )

#放入 lib 文件夹
INSTALL(TARGETS
    XYY_Game_Engine
    LIBRARY DESTINATION
    ${CMAKE_CURRENT_LIST_DIR}/lib/
)

#放入 bin 中
INSTALL(FILES
    ${CMAKE_CURRENT_LIST_DIR}/dll/Release/XYY_Game_Engine.dll
    DESTINATION
    ${CMAKE_CURRENT_LIST_DIR}/bin/
)

INSTALL(FILES
    ${CMAKE_CURRENT_LIST_DIR}/dll/assimp-vc142-mt.dll
    DESTINATION
    ${CMAKE_CURRENT_LIST_DIR}/bin
)

#对 test 增加支持   dll  release
INSTALL(FILES
    ${CMAKE_CURRENT_LIST_DIR}/bin/assimp-vc142-mt.dll
    DESTINATION
    ${CMAKE_CURRENT_LIST_DIR}/build/test/Release
)

INSTALL(FILES
    ${CMAKE_CURRENT_LIST_DIR}/bin/XYY_Game_Engine.dll
    DESTINATION
    ${CMAKE_CURRENT_LIST_DIR}/build/test/Release
)
INSTALL(FILES
    ${CMAKE_CURRENT_LIST_DIR}/bin/assimp-vc142-mt.dll
    DESTINATION
    ${CMAKE_CURRENT_LIST_DIR}/build/test/Debug
)
INSTALL(FILES
    ${CMAKE_CURRENT_LIST_DIR}/bin/XYY_Game_Engine.dll
    DESTINATION
    ${CMAKE_CURRENT_LIST_DIR}/build/test/Debug
)
# example 
INSTALL(
    DIRECTORY
    ${CODE_ROOT_PATH}/Scxmlexample
    DESTINATION
    ${TEST_PATH}/
)
# resources
INSTALL(
    DIRECTORY
    ${CODE_ROOT_PATH}/resources
    DESTINATION
    ${TEST_PATH}/
)
# header
INSTALL(
    DIRECTORY
    ${CMAKE_CURRENT_LIST_DIR}/include
    DESTINATION
    ${TEST_PATH}/
)


#target main
#add_executable(main main.cpp)
#ADD_DEPENDENCIES(main XYY_Game_Engine)
#target_link_libraries(main XYY_Game_Engine.lib)

#target 测试
add_subdirectory(test)


