add_executable(
    ${PROJECT_NAME}
    source/main.cpp
    include/main.hpp
)

target_compile_definitions(${PROJECT_NAME} PRIVATE MAIN_APPLICATION_XML="/home/shivang/Documents/just_edit/src/gui/justedit.ui")
    
target_link_directories(${PROJECT_NAME} PUBLIC ${GTKMM_LIBRARY_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${GTKMM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${GTKMM_LIBRARIES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
