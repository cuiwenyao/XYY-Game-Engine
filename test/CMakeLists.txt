#对于每一个项目，其相对路径的起始位置是 vs 那一对文件的位置
#test1
add_executable(test1 test1.cpp)
ADD_DEPENDENCIES(test1 XYY_Game_Engine)
target_link_libraries(test1 XYY_Game_Engine)

#test1
add_executable(test2 test2.cpp)
ADD_DEPENDENCIES(test1 XYY_Game_Engine)
target_link_libraries(test2 XYY_Game_Engine)
