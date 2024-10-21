cmake_minimum_required(VERSION 3.12)
project(hwDocker VERSION 1.0.0 LANGUAGES CXX)

# Устанавливаем стандарт C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем папку include для поиска заголовочных файлов
include_directories(${PROJECT_SOURCE_DIR}/include)

# Добавляем все файлы в src как исходные файлы проекта
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Указываем целевую сборку
add_executable(proga ${SRC_FILES})
