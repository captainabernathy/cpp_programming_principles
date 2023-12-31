add_executable(ch_12_03_first_example ch_12_03_first_example.cpp)
target_link_libraries(ch_12_03_first_example
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_02_an_almost_blank_window
               ch_12_07_02_an_almost_blank_window.cpp)
target_link_libraries(ch_12_07_02_an_almost_blank_window
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_03_01_axis_simple ch_12_07_03_01_axis_simple.cpp)
target_link_libraries(ch_12_07_03_01_axis_simple
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_03_02_axis_properties
               ch_12_07_03_02_axis_properties.cpp)
target_link_libraries(ch_12_07_03_02_axis_properties
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_04_graphing_a_function
               ch_12_07_04_graphing_a_function.cpp)
target_link_libraries(ch_12_07_04_graphing_a_function
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_05_polygons ch_12_07_05_polygons.cpp)
target_link_libraries(ch_12_07_05_polygons
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_06_00_rectangles ch_12_07_06_00_rectangles.cpp)
target_link_libraries(ch_12_07_06_00_rectangles
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_06_01_poly_rect ch_12_07_06_01_poly_rect.cpp)
target_link_libraries(ch_12_07_06_01_poly_rect
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_06_02_more_polyshapes
               ch_12_07_06_02_more_polyshapes.cpp)
target_link_libraries(ch_12_07_06_02_more_polyshapes
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_07_fill ch_12_07_07_fill.cpp)
target_link_libraries(ch_12_07_07_fill
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_08_01_text ch_12_07_08_01_text.cpp)
target_link_libraries(ch_12_07_08_01_text
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_08_02_text_properties
               ch_12_07_08_02_text_properties.cpp)
target_link_libraries(ch_12_07_08_02_text_properties
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_09_01_images ch_12_07_09_01_images.cpp)
target_link_libraries(ch_12_07_09_01_images
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_09_02_image_properties
               ch_12_07_09_02_image_properties.cpp)
target_link_libraries(ch_12_07_09_02_image_properties
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_12_07_10_more_features ch_12_07_10_more_features.cpp)
target_link_libraries(ch_12_07_10_more_features
                      PRIVATE
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_custom_command(
    TARGET ch_12_07_09_01_images POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/image.jpg
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/image.jpg
)

add_custom_command(
    TARGET ch_12_07_10_more_features POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/snow_cpp.gif
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/snow_cpp.gif
)
