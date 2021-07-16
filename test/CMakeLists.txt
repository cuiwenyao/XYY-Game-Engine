#对于每一个项目，其相对路径的起始位置是 vs 那一对文件的位置

#xml
FILE(
    GLOB_RECURSE SRC_Scxmlexample_test
    ${CODE_ROOT_PATH}/Scxmlexample/*.xml
)
source_group(Scxmlexample FILES ${SRC_Scxmlexample_test})

#test1
add_executable(test1 test1.cpp ${SRC_Scxmlexample_test})
ADD_DEPENDENCIES(test1 XYY_Game_Engine)
target_link_libraries(test1 XYY_Game_Engine)

#test1
add_executable(test2 test2.cpp ${SRC_Scxmlexample_test})
ADD_DEPENDENCIES(test1 XYY_Game_Engine)
target_link_libraries(test2 XYY_Game_Engine)


