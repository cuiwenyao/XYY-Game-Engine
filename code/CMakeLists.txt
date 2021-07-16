#code 

#code 中的所有文件
FILE(GLOB_RECURSE SOURCE_CODE       
    Driver/*
    Driver/LocalDriver/*
    Driver/GlobalDriver/*
    Element/*
    Resource/*
    Scene/*
    Sync/*
    ${INCLUDE_PATH_CONTRIB}/*.c
)

#组织 file 
#Driver
FILE(
    GLOB_RECURSE SRC_Driver
    Driver/*.hpp
)
source_group(Driver FILES ${SRC_Driver})
FILE(
    GLOB_RECURSE SRC_Driver_LocalDriver
    Driver/LocalDriver/*
)
source_group(Driver//LocalDriver FILES ${SRC_Driver_LocalDriver})
FILE(
    GLOB_RECURSE SRC_Driver_Global
    Driver/GlobalDriver/*
)
source_group(Driver//GlobalDriver FILES ${SRC_Driver_Global})
#SRC_Element
FILE(
    GLOB_RECURSE SRC_Element
    Element/*
)
source_group(Element FILES ${SRC_Element})
#SRC_Resource
FILE(
    GLOB_RECURSE SRC_Resource
    Resource/*
)
source_group(Resource FILES ${SRC_Resource})
#SRC_Resource
FILE(
    GLOB_RECURSE SRC_Scene
    Scene/*
)
source_group(Scene FILES ${SRC_Scene})
#SRC_Sync
FILE(
    GLOB_RECURSE SRC_Sync
    Sync/*
)
source_group(Sync FILES ${SRC_Sync})
#xml
FILE(
    GLOB_RECURSE SRC_Scxmlexample
    ${CODE_ROOT_PATH}/Scxmlexample/*.xml
)
source_group(Scxmlexample FILES ${SRC_Scxmlexample})




FILE(
    GLOB DEPENDENCE_LIB
    ${LIBRARY_PATH_CONTRIB}/*.lib
)

#生成链接库
add_library(XYY_Game_Engine SHARED ${SOURCE_CODE} ${SRC_Scxmlexample})
SetDefaultTargetProperties(XYY_Game_Engine)
#  应该还要加上 opengl32.lib
target_link_libraries(XYY_Game_Engine   
opengl32  
glfw3.lib 
assimp-vc142-mt.lib  
tinyxml.lib  
kernel32.lib
user32.lib
gdi32.lib
winspool.lib
comdlg32.lib
advapi32.lib
shell32.lib
ole32.lib
oleaut32.lib
uuid.lib
odbc32.lib
odbccp32.lib
)



