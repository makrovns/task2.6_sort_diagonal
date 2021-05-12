# задаем набор исходников
set(SOURCES
    tests.cpp
)

# создаем исполняемый файл
add_executable(mymatrix_test ${SOURCES})

# подключаем библиотеки:
# 1. Тестируемая библиотека
# 2. gest
target_link_libraries(mymatrix_test PUBLIC matrix_lib)
target_link_libraries(mymatrix_test PUBLIC gtest_main)

# В solution эта библиотека лежит в tests/mymatrix_test
set_property(TARGET mymatrix_test PROPERTY FOLDER "tests/mymatrix_test")