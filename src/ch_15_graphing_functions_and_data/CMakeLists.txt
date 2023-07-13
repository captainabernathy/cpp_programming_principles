add_executable(ch_15_02_01_function_graphing_plain
               ch_15_02_01_function_graphing_plain.cpp)
target_link_libraries(ch_15_02_01_function_graphing_plain
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_15_02_02_function_graphing_labels
               ch_15_02_02_function_graphing_labels.cpp)
target_link_libraries(ch_15_02_02_function_graphing_labels
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_15_02_03_function_graphing_notches
               ch_15_02_03_function_graphing_notches.cpp)
target_link_libraries(ch_15_02_03_function_graphing_notches
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_15_02_04_function_graphing_colors
               ch_15_02_04_function_graphing_colors.cpp)
target_link_libraries(ch_15_02_04_function_graphing_colors
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_15_03_02_01_function_graphing_more_examples
               ch_15_03_02_01_function_graphing_more_examples.cpp)
target_link_libraries(ch_15_03_02_01_function_graphing_more_examples
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_15_03_02_02_function_graphing_log_exp_sin_cos
               ch_15_03_02_02_function_graphing_log_exp_sin_cos.cpp)
target_link_libraries(ch_15_03_02_02_function_graphing_log_exp_sin_cos
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_15_05_approximation ch_15_05_approximation.cpp)
target_link_libraries(ch_15_05_approximation
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_15_06_graphing_data ch_15_06_graphing_data.cpp)
target_link_libraries(ch_15_06_graphing_data
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_custom_command(
    TARGET ch_15_06_graphing_data POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/japanese-age-data.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/japanese-age-data.txt
)
