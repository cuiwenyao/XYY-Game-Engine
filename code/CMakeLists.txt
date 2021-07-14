#code 

#code 中的所有文件
FILE(GLOB_RECURSE SOURCE_CODE       
    Component/*
    Driver/*
    Driver/LocalDriver/*
    Driver/Global/*
    Element/*
    Resource/*
    Scene/*
    Sync/*
    ${INCLUDE_PATH_CONTRIB}/*.c
)



FILE(
    GLOB DEPENDENCE_LIB
    ${LIBRARY_PATH_CONTRIB}/*.lib
)

#生成链接库
add_library(XYY_Game_Engine SHARED ${SOURCE_CODE})
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