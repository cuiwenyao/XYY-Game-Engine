aux_source_directory(. DIR_XYY_Game_Engine_LIB_SRCS)

FILE(GLOB SOURCE_CODE       
    Component/*
    Driver/*
    Driver/LocalDriver/*
    Driver/Global/*
    Element/*
    Resource/*
    Scene/*
    Sync/*
)

FILE(GLOB DEPENDENCE_LIBS
    ${PROJECT_SOURCE_DIR}/contrib/lib/*
)

FILE(GLOB EXTERNAL_HEADERS
    ${PROJECT_SOURCE_DIR}/contrib/include/*
    ${PROJECT_SOURCE_DIR}/contrib/include/assimp/*
    ${PROJECT_SOURCE_DIR}/contrib/include/assimp/Compiler/*
    ${PROJECT_SOURCE_DIR}/contrib/include/port/*
    ${PROJECT_SOURCE_DIR}/contrib/include/glad/*
    ${PROJECT_SOURCE_DIR}/contrib/include/GLFW/*
    ${PROJECT_SOURCE_DIR}/contrib/include/glm/*
    ${PROJECT_SOURCE_DIR}/contrib/include/glm/detail/*
    ${PROJECT_SOURCE_DIR}/contrib/include/ext/*
    ${PROJECT_SOURCE_DIR}/contrib/include/gtc/*
    ${PROJECT_SOURCE_DIR}/contrib/include/gtx/*
    ${PROJECT_SOURCE_DIR}/contrib/include/simd/*
    ${PROJECT_SOURCE_DIR}/contrib/include/KHR/*
    ${PROJECT_SOURCE_DIR}/contrib/include/Tinyxml/*
)

#assimp-vc142-mt.dll
#link_libraries( glfw3.lib tinyxml.lib)

#引用目录
INCLUDE_DIRECTORIES(${THIRD_PART_INCLUDE_PATH})
#库目录
LINK_DIRECTORIES(${THIRD_PART_LIB_PATH})

#生成链接库
add_library(XYY_Game_Engine STATIC ${SOURCE_CODE})


find_library(THIRD_PART_LIB NAMES jsoncpp PATHS ./jsoncpp)

target_link_libraries(XYY_Game_Engine assimp-vc142-mt.lib assimp-vc142-mt.dll glfw3.lib tinyxml.lib)


#MESSAGE(status ${DEPENDENCE_LIBS}\n)

#设置语言
SET_TARGET_PROPERTIES(XYY_Game_Engine PROPERTIES LINKER_LANGUAGE C++)

