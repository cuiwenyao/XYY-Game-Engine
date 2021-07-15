# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_Scene_LIB_SRCS)

# 生成链接库
add_library (Scene STATIC ${DIR_Scene_LIB_SRCS})

# 指定 MathFunctions 库的安装路径

#install(TARGETS Component DESTINATION ${PROJECT_SOURCE_DIR}/lib)

#install(FILES "power.h" DESTINATION ${PROJECT_SOURCE_DIR}/include)