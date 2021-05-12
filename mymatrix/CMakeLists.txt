# задаем набор исходников
set(SOURCES
mymatrix_library.h
mymatrix_library.cpp
)

# создаем статическую библиотеку
add_library(matrix_lib ${SOURCES})

# добавлем путь к исходникам для возожности подключения библиотеки
target_include_directories(matrix_lib PUBLIC ${SRC_ROOT_DIR})

# группируем исходники по типу по категориям
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES})

# В solution эта библиотека лежит в simple_project
set_property(TARGET matrix_lib PROPERTY FOLDER "matrix_project")

# включаем в сборку проекnа подпроект с тестами
add_subdirectory(tests)