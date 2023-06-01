add_executable(ch_13_02_point_and_line ch_13_02_point_and_line.cpp)
add_executable(ch_13_03_01_lines_object ch_13_03_01_lines_object.cpp)
add_executable(ch_13_03_02_grid ch_13_03_02_grid.cpp)
add_executable(ch_13_04_color ch_13_04_color.cpp)
add_executable(ch_13_05_01_line_style_dot_grid
               ch_13_05_01_line_style_dot_grid.cpp)
add_executable(ch_13_05_02_line_style_dash_weighted
               ch_13_05_02_line_style_dash_weighted.cpp)
add_executable(ch_13_05_03_two_lines_colored ch_13_05_03_two_lines_colored.cpp)
add_executable(ch_13_06_open_polyline ch_13_06_open_polyline.cpp)
add_executable(ch_13_07_closed_polyline ch_13_07_closed_polyline.cpp)
add_executable(ch_13_08_01_improper_polygon ch_13_08_01_improper_polygon.cpp)
add_executable(ch_13_08_02_polygon ch_13_08_02_polygon.cpp)
add_executable(ch_13_09_01_rectangles_01 ch_13_09_01_rectangles_01.cpp)
add_executable(ch_13_09_02_rectangles_02 ch_13_09_02_rectangles_02.cpp)
add_executable(ch_13_09_03_rectangles_03 ch_13_09_03_rectangles_03.cpp)
add_executable(ch_13_09_04_rectangles_04 ch_13_09_04_rectangles_04.cpp)
add_executable(ch_13_10_01_unnamed_objects_01
               ch_13_10_01_unnamed_objects_01.cpp)
add_executable(ch_13_10_02_color_palette ch_13_10_02_color_palette.cpp)
add_executable(ch_13_11_text ch_13_11_text.cpp)
add_executable(ch_13_12_circle ch_13_12_circle.cpp)
add_executable(ch_13_13_ellipse ch_13_13_ellipse.cpp)
add_executable(ch_13_14_marked_polyline ch_13_14_marked_polyline.cpp)
add_executable(ch_13_15_marks ch_13_15_marks.cpp)
add_executable(ch_13_16_mark ch_13_16_mark.cpp)
add_executable(ch_13_17_images ch_13_17_images.cpp)

target_link_libraries(ch_13_02_point_and_line bookgui fltk fltk_images X11)
target_link_libraries(ch_13_03_01_lines_object bookgui fltk fltk_images X11)
target_link_libraries(ch_13_03_02_grid bookgui fltk fltk_images X11)
target_link_libraries(ch_13_04_color bookgui fltk fltk_images X11)
target_link_libraries(ch_13_05_01_line_style_dot_grid
                      bookgui fltk fltk_images X11)
target_link_libraries(ch_13_05_02_line_style_dash_weighted
                      bookgui fltk fltk_images X11)
target_link_libraries(ch_13_05_03_two_lines_colored
                      bookgui fltk fltk_images X11)
target_link_libraries(ch_13_06_open_polyline bookgui fltk fltk_images X11)
target_link_libraries(ch_13_07_closed_polyline bookgui fltk fltk_images X11)
target_link_libraries(ch_13_08_01_improper_polygon
                      bookgui fltk fltk_images X11)
target_link_libraries(ch_13_08_02_polygon bookgui fltk fltk_images X11)
target_link_libraries(ch_13_09_01_rectangles_01 bookgui fltk fltk_images X11)
target_link_libraries(ch_13_09_02_rectangles_02 bookgui fltk fltk_images X11)
target_link_libraries(ch_13_09_03_rectangles_03 bookgui fltk fltk_images X11)
target_link_libraries(ch_13_09_04_rectangles_04 bookgui fltk fltk_images X11)
target_link_libraries(ch_13_10_01_unnamed_objects_01
                      bookgui fltk fltk_images X11)
target_link_libraries(ch_13_10_02_color_palette bookgui fltk fltk_images X11)
target_link_libraries(ch_13_11_text bookgui fltk fltk_images X11)
target_link_libraries(ch_13_12_circle bookgui fltk fltk_images X11)
target_link_libraries(ch_13_13_ellipse bookgui fltk fltk_images X11)
target_link_libraries(ch_13_14_marked_polyline bookgui fltk fltk_images X11)
target_link_libraries(ch_13_15_marks bookgui fltk fltk_images X11)
target_link_libraries(ch_13_16_mark bookgui fltk fltk_images X11)
target_link_libraries(ch_13_17_images bookgui fltk fltk_images X11)

add_custom_command(
    TARGET ch_13_17_images POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/rita.jpg
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/rita.jpg
)

add_custom_command(
    TARGET ch_13_17_images POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/rita_path.gif
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/rita_path.gif
)

