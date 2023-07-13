add_executable(ch_13_02_point_and_line ch_13_02_point_and_line.cpp)
target_link_libraries(ch_13_02_point_and_line
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_03_01_lines_object ch_13_03_01_lines_object.cpp)
target_link_libraries(ch_13_03_01_lines_object
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_03_02_grid ch_13_03_02_grid.cpp)
target_link_libraries(ch_13_03_02_grid
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_04_color ch_13_04_color.cpp)
target_link_libraries(ch_13_04_color
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_05_01_line_style_dot_grid
               ch_13_05_01_line_style_dot_grid.cpp)
target_link_libraries(ch_13_05_01_line_style_dot_grid
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_05_02_line_style_dash_weighted
               ch_13_05_02_line_style_dash_weighted.cpp)
target_link_libraries(ch_13_05_02_line_style_dash_weighted
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_05_03_two_lines_colored ch_13_05_03_two_lines_colored.cpp)
target_link_libraries(ch_13_05_03_two_lines_colored
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_06_open_polyline ch_13_06_open_polyline.cpp)
target_link_libraries(ch_13_06_open_polyline
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_07_closed_polyline ch_13_07_closed_polyline.cpp)
target_link_libraries(ch_13_07_closed_polyline
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_08_01_improper_polygon ch_13_08_01_improper_polygon.cpp)
target_link_libraries(ch_13_08_01_improper_polygon
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_08_02_polygon ch_13_08_02_polygon.cpp)
target_link_libraries(ch_13_08_02_polygon
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_09_01_rectangles_01 ch_13_09_01_rectangles_01.cpp)
target_link_libraries(ch_13_09_01_rectangles_01
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_09_02_rectangles_02 ch_13_09_02_rectangles_02.cpp)
target_link_libraries(ch_13_09_02_rectangles_02
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_09_03_rectangles_03 ch_13_09_03_rectangles_03.cpp)
target_link_libraries(ch_13_09_03_rectangles_03
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_09_04_rectangles_04 ch_13_09_04_rectangles_04.cpp)
target_link_libraries(ch_13_09_04_rectangles_04
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_10_01_unnamed_objects_01
               ch_13_10_01_unnamed_objects_01.cpp)
target_link_libraries(ch_13_10_01_unnamed_objects_01
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_10_02_color_palette ch_13_10_02_color_palette.cpp)
target_link_libraries(ch_13_10_02_color_palette
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_11_text ch_13_11_text.cpp)
target_link_libraries(ch_13_11_text
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_12_circle ch_13_12_circle.cpp)
target_link_libraries(ch_13_12_circle
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_13_ellipse ch_13_13_ellipse.cpp)
target_link_libraries(ch_13_13_ellipse
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_14_marked_polyline ch_13_14_marked_polyline.cpp)
target_link_libraries(ch_13_14_marked_polyline
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_15_marks ch_13_15_marks.cpp)
target_link_libraries(ch_13_15_marks
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_16_mark ch_13_16_mark.cpp)
target_link_libraries(ch_13_16_mark
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_13_17_images ch_13_17_images.cpp)
target_link_libraries(ch_13_17_images
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

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
