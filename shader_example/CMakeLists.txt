cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME shader_example)
set(CMAKE_CXX_STANDARD 17)

set(WINDOW_NAME "Shader OpenGL Example")
set(WINDOW_WIDTH 960)
set(WINDOW_HEIGHT 540)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} 
src/main.cpp
src/common.cpp src/common.h
src/shader.cpp src/shader.h
src/program.cpp src/program.h
src/context.cpp src/context.h
)
include(Dependency.cmake)


# 우리 프로젝트에 include / lib 관련 옵션 추가
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

# 위에 셋팅해놓은 변수 값을 컴파일 데피니션을 통해 선언
# c++의 #define과 동일함. 이것을 외부에서 선언할 수 있도록 CMAKE에 작성할 수 있음
target_compile_definitions(${PROJECT_NAME} PUBLIC
WINDOW_NAME="${WINDOW_NAME}"
WINDOW_WIDTH=${WINDOW_WIDTH}
WINDOW_HEIGHT=${WINDOW_HEIGHT}
)

# 우리 프로젝트 안의 파일들이 컴파일 되기 전에 Dependency들이 먼저 build 될 수 있게 관계 설정
add_dependencies(${PROJECT_NAME} ${DEP_LIST})