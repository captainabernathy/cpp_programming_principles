add_executable(ch_05_03_03_improper_calls ch_05_03_03_improper_calls.cpp)
add_executable(ch_05_05_01_exceptions_01 ch_05_05_01_exceptions_01.cpp)
add_executable(ch_05_05_02_exceptions_02 ch_05_05_02_exceptions_02.cpp)
add_executable(ch_05_06_01_exceptions_03 ch_05_06_01_exceptions_03.cpp)
add_executable(ch_05_06_04_exceptions_04_narrow_cast_template
               ch_05_06_04_exceptions_04_narrow_cast_template.cpp)
add_executable(ch_05_07_logic_errors ch_05_07_logic_errors.cpp)
add_executable(ch_05_09_01_exceptions_05 ch_05_09_01_exceptions_05.cpp)
add_executable(ch_05_11_exceptions_06 ch_05_11_exceptions_06.cpp)

target_compile_definitions(ch_05_05_01_exceptions_01 PRIVATE -DERR_OUT)
target_compile_definitions(ch_05_05_02_exceptions_02 PRIVATE -DERR_OUT)
target_compile_definitions(ch_05_06_01_exceptions_03 PRIVATE -DERR_OUT)
target_compile_definitions(ch_05_06_04_exceptions_04_narrow_cast_template
                           PRIVATE -DERR_OUT)
target_compile_definitions(ch_05_09_01_exceptions_05 PRIVATE -DERR_OUT)
target_compile_definitions(ch_05_11_exceptions_06 PRIVATE -DERR_OUT)

