add_executable(ch_06_03_01_calc_attempt_01 ch_06_03_01_calc_attempt_01.cpp)
add_executable(ch_06_03_01_calc_attempt_02 ch_06_03_01_calc_attempt_02.cpp)
add_executable(ch_06_03_03_token_01 ch_06_03_03_token_01.cpp)
add_executable(ch_06_07_token_stream_01 ch_06_07_token_stream_01.cpp)
add_executable(ch_06_08_01_token_stream_test_01
               ch_06_08_01_token_stream_test_01.cpp)
add_executable(ch_06_08_02_token_stream_test_02
               ch_06_08_02_token_stream_test_02.cpp)
add_executable(ch_06_09_token_stream_02 ch_06_09_token_stream_02.cpp)

target_compile_definitions(ch_06_03_01_calc_attempt_02 PRIVATE -DERR_OUT)
target_compile_definitions(ch_06_07_token_stream_01 PRIVATE -DERR_OUT)
target_compile_definitions(ch_06_08_01_token_stream_test_01 PRIVATE -DERR_OUT)
target_compile_definitions(ch_06_08_02_token_stream_test_02 PRIVATE -DERR_OUT)
target_compile_definitions(ch_06_09_token_stream_02 PRIVATE -DERR_OUT)

