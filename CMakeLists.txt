cmake_minimum_required(VERSION 3.19)

if (APPLE)
    message(FATAL_ERROR "You're currently working on an Apple machine! Apple and their platforms are not supported, if
you wish to help with adding support for apple devices, please make pull request on the main engine repository as well
as on the UVKBuildTool repository(this file is generated by it!) and consider maintaining the apple builds!")
endif()

project(UntitledImGuiFramework)
project(UntitledImageViewer)

set(CMAKE_CXX_STANDARD 20)

# ----------------------------------------------------------------------------------------------------------------------
# ------------------------------------------------- Add subdirectories -------------------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

add_subdirectory(Framework/ThirdParty/glfw)
add_subdirectory(Framework/ThirdParty/glew)
set(BUILD_SHARED_LIBS ON)
add_subdirectory(Framework/ThirdParty/yaml-cpp)
set(BUILD_SHARED_LIBS OFF)

# ----------------------------------------------------------------------------------------------------------------------
# ------------------------------------------------- Add compile options ------------------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

option(USE_OS_MODULE "Use the operating system module" ON)
if (USE_OS_MODULE)
    option(ENABLE_DBUS_UTILS "Compile in additional utility functions that make using the C DBus API safer" OFF)
    option(ENABLE_UEXEC "Compile in the UntitledExec library for a cross-platform method of launching applications" OFF)
    option(ENABLE_THEMING "Compile in the UDE theme integration system for supporting theming in your application" ON)
    option(ENABLE_NOTIFICATIONS "Compile in support for cross platform notifications" OFF)
    option(ENABLE_POLKIT_UTILS "Compile in utilities for dealing with polkit" OFF)
    option(ENABLE_UFONT_UTILS "Compiles in cross-platform utilities for dealing with system fonts" OFF)

    if (ENABLE_DBUS_UTILS)
        find_package(PkgConfig REQUIRED)
        pkg_check_modules(DBUS REQUIRED dbus-1)

        link_directories(${DBUS_LIBRARY_DIRS})
        include_directories(${DBUS_INCLUDE_DIRS})
    endif()
    if (ENABLE_UEXEC)
        include_directories("Framework/Modules/OS/ThirdParty/" "Framework/Modules/OS/ThirdParty/uexec")
    endif()
    if (ENABLE_THEMING)

    endif()
    if (ENABLE_NOTIFICATIONS)

    endif()
    if (ENABLE_POLKIT_UTILS)

    endif()
    if (ENABLE_UFONT_UTILS)
        find_package(Fontconfig REQUIRED)
    endif()
endif()

option(USE_AUDIO_MODULE "Use the audio module" OFF)
option(USE_LOCALE_MODULE "Use the locale module" ON)
option(USE_NETWORKING_MODULE "Use the networking module" OFF)   # Not functional right now
option(USE_UNDO_MODULE "Use the Undo/Redo module" OFF)          # Not functional right now
option(USE_VIDEO_MODULE "Use the video module" OFF)             # Not functional right now

# Styling and GUI widgets modules
option(USE_PLOTTING_MODULE "Use the plotting module" OFF)
option(USE_KNOBS_MODULE "Use the knobs module" ON)
option(USE_SPINNER_MODULE "Use the spinners module" OFF)
option(USE_TOGGLES_MODULE "Use the toggles module" OFF)
option(USE_TEXT_UTILS_MODULE "Use the text utils module" OFF)
option(USE_MARKDOWN_MODULE "Use the markdown rendering module" OFF)

# Patch by the UntitledImageViewer
option(USE_AVIF_SUPPORT "Turn on AVIF and HEIF" ON)
option(USE_JPEG_XL_SUPPORT "Turn on support for JPEG XL" ON)
option(USE_WEBP_SUPPORT "Turn on support for WebP" ON)

if (USE_AVIF_SUPPORT)
    add_subdirectory(ThirdParty/libavif)
endif()

if (USE_JPEG_XL_SUPPORT)
    add_subdirectory(ThirdParty/libjxl)
endif()

if (USE_WEBP_SUPPORT)
    add_subdirectory(ThirdParty/libwebp)
endif()

# ----------------------------------------------------------------------------------------------------------------------
# ---------------------------------------------- Add files and directories ---------------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

include_directories("Source/" "Framework/ThirdParty/yaml-cpp/include/yaml-cpp" "Framework/"
        "Framework/ThirdParty/imgui/backends/everything/" "Framework/ThirdParty/imgui/backends/Vulkan/"
        "Framework/ThirdParty/imgui/misc/" "Framework/ThirdParty/glfw/include" "Framework/ThirdParty/glew/include"
        "Framework/ThirdParty/imgui/backends/everything" "Framework/ThirdParty/imgui/" "Framework/Core/"
        "Framework/Renderer/" "Framework/ThirdParty/logger/src/" "Framework/ThirdParty/source-libraries/"
        "Framework/ThirdParty/yaml-cpp/include" "Framework/Modules")


link_directories("ThirdParty/glew/lib" UVKBuildTool/build)

file(GLOB_RECURSE UGUI_SRC "Framework/Core/*.cpp" "Framework/Renderer/*.cpp"
        "Framework/ThirdParty/imgui/backends/everything/*.cpp" "Framework/ThirdParty/imgui/misc/cpp/*.cpp"
        "Framework/ThirdParty/logger/*.cpp" "Framework/ThirdParty/source-libraries/*.cpp"
        "Framework/Modules/Audio/src/*.cpp" "Framework/Modules/Locale/src/*.cpp" "Source/*.cpp"
        "Framework/Modules/Undo/src/*.cpp" "Framework/Modules/Manager/*.cpp" "Framework/Modules/OS/*.cpp"
        "Framework/Modules/Modules.hpp")
file(GLOB_RECURSE UGUI_HEAD "Framework/Core/*.hpp" "Framework/Renderer/*.hpp"
        "Framework/ThirdParty/imgui/backends/everything/*.h" "Framework/ThirdParty/imgui/misc/cpp/*.h"
        "Framework/ThirdParty/logger/*.h" "Framework/ThirdParty/source-libraries/*.h"
        "Framework/ThirdParty/source-libraries/*.hpp" "Framework/Modules/Audio/src/*.hpp"
        "Framework/Modules/Locale/src/*.hpp" "Source/*.hpp" "Framework/Modules/Undo/src/*.hpp"
        "Framework/Modules/Manager/*.hpp" "Framework/Modules/OS/*.h" "Framework/Modules/OS/*.hpp")
file(GLOB_RECURSE EXEC_SRC "")

# ----------------------------------------------------------------------------------------------------------------------
# ----------------------------------------------- Modify files for modules ---------------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

if (USE_PLOTTING_MODULE)
    file(GLOB_RECURSE UGUI_IMPLOT_SRC "Framework/Modules/Plotting/*.cpp")
    file(GLOB_RECURSE UGUI_IMPLOT_HEAD "Framework/Modules/Plotting/*.hpp")
else()
    file(GLOB_RECURSE UGUI_IMPLOT_SRC )
    file(GLOB_RECURSE UGUI_IMPLOT_HEAD )
endif()

if (USE_KNOBS_MODULE)
    file(GLOB_RECURSE UGUI_KNOBS_SRC "Framework/Modules/Knobs/*.cpp")
    file(GLOB_RECURSE UGUI_KNOBS_HEAD "Framework/Modules/Knobs/*.h")
else()
    file(GLOB_RECURSE UGUI_KNOBS_SRC )
    file(GLOB_RECURSE UGUI_KNOBS_HEAD )
endif()

if (USE_SPINNER_MODULE)
    file(GLOB_RECURSE UGUI_SPINNER_HEAD "Framework/Modules/Spinners/*.h")
else()
    file(GLOB_RECURSE UGUI_SPINNER_HEAD )
endif()

if (USE_TOGGLES_MODULE)
    file(GLOB_RECURSE UGUI_TOGGLES_SRC "Framework/Modules/Toggles/*.cpp")
    file(GLOB_RECURSE UGUI_TOGGLES_HEAD "Framework/Modules/Toggles/*.h")
else()
    file(GLOB_RECURSE UGUI_TOGGLES_SRC )
    file(GLOB_RECURSE UGUI_TOGGLES_HEAD )
endif()

if (USE_OS_MODULE)
    if (ENABLE_UEXEC)
        file(GLOB_RECURSE UGUI_UEXEC_SRC "Framework/Modules/OS/ThirdParty/uexec/*.cpp")
        file(GLOB_RECURSE UGUI_UEXEC_HEAD "Framework/Modules/OS/ThirdParty/uexec/*.hpp"
                "Framework/Modules/OS/ThirdParty/uexec/*.h")
    else()
        file(GLOB_RECURSE UGUI_UEXEC_SRC )
        file(GLOB_RECURSE UGUI_UEXEC_HEAD )
    endif()

    file(GLOB_RECURSE UGUI_OS_SRC ${UGUI_UEXEC_SRC})
    file(GLOB_RECURSE UGUI_OS_HEAD ${UGUI_UEXEC_HEAD})
else()
    file(GLOB_RECURSE UGUI_OS_SRC )
    file(GLOB_RECURSE UGUI_OS_HEAD )
endif()

# ----------------------------------------------------------------------------------------------------------------------
# --------------------------------------------------- Compile binaries -------------------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

add_library(UntitledImGuiFramework SHARED ${UGUI_SRC} ${UGUI_HEAD} Generated/BuildDef.hpp ${UGUI_IMPLOT_SRC}
        ${UGUI_IMPLOT_HEAD} ${UGUI_OS_SRC} ${UGUI_OS_HEAD} ${UGUI_TOGGLES_HEAD} ${UGUI_TOGGLES_SRC} ${UGUI_SPINNER_HEAD}
        ${UGUI_KNOBS_HEAD} ${UGUI_KNOBS_SRC})
add_executable(UntitledImageViewer Generated/main.cpp ${UGUI_HEAD} ${EXEC_SRC} Generated/BuildDef.hpp ${UGUI_IMPLOT_HEAD}
        ${UGUI_OS_HEAD} ${UGUI_TOGGLES_HEAD} ${UGUI_SPINNER_HEAD} ${UGUI_KNOBS_HEAD})

# ----------------------------------------------------------------------------------------------------------------------
# ----------------------------------------------- Set up linker properties ---------------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

set_target_properties(UntitledImGuiFramework PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(UntitledImageViewer PROPERTIES LINKER_LANGUAGE CXX)

# ----------------------------------------------------------------------------------------------------------------------
# ------------------------------------------- Set up module compiler definitions ---------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

if (USE_AUDIO_MODULE)
    target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_AUDIO_MODULE_ENABLED")
    target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_AUDIO_MODULE_ENABLED")
endif()

if (USE_LOCALE_MODULE)
    target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_LOCALE_MODULE_ENABLED")
    target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_LOCALE_MODULE_ENABLED")
endif()

if (USE_PLOTTING_MODULE)
    target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_PLOTTING_MODULE_ENABLED")
    target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_PLOTTING_MODULE_ENABLED")
endif()

if (USE_KNOBS_MODULE)
    target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_KNOBS_MODULE_ENABLED")
    target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_KNOBS_MODULE_ENABLED")
endif()

if (USE_SPINNER_MODULE)
    target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_SPINNERS_MODULE_ENABLED")
    target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_SPINNERS_MODULE_ENABLED")
endif()

if (USE_TOGGLES_MODULE)
    target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_TOGGLES_MODULE_ENABLED")
    target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_TOGGLES_MODULE_ENABLED")
endif()

if (USE_UNDO_MODULE)
    target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_UNDO_MODULE_ENABLED")
    target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_UNDO_MODULE_ENABLED")
endif()

if (USE_OS_MODULE)
    target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_OS_MODULE_ENABLED")
    target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_OS_MODULE_ENABLED")

    if (ENABLE_DBUS_UTILS)
        target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_DBUS_SUBMODULE_ENABLED")
        target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_DBUS_SUBMODULE_ENABLED")
    endif()
    if (ENABLE_UEXEC)
        target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_UEXEC_SUBMODULE_ENABLED")
        target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_UEXEC_SUBMODULE_ENABLED")
    endif()
    if (ENABLE_THEMING)
        target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_THEME_SUBMODULE_ENABLED")
        target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_THEME_SUBMODULE_ENABLED")
    endif()
    if (ENABLE_NOTIFICATIONS)
        target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_NOTIFY_SUBMODULE_ENABLED")
        target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_NOTIFY_SUBMODULE_ENABLED")
    endif()
    if (ENABLE_POLKIT_UTILS)
        target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_POLKIT_SUBMODULE_ENABLED")
        target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_POLKIT_SUBMODULE_ENABLED")
    endif()
    if (ENABLE_UFONT_UTILS)
        target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_UFONT_UTILS_SUBMODULE_ENABLED")
        target_compile_definitions(UntitledImageViewer PRIVATE "UIMGUI_UFONT_UTILS_SUBMODULE_ENABLED")
    endif()
endif()

if (USE_AVIF_SUPPORT)
    target_compile_definitions(UntitledImageViewer PRIVATE "USE_AVIF")
endif()

if (USE_JPEG_XL_SUPPORT)
    target_compile_definitions(UntitledImageViewer PRIVATE "USE_JPEG_XL")
endif()

if (USE_WEBP_SUPPORT)
    target_compile_definitions(UntitledImageViewer PRIVATE "USE_WEBP")
endif()

# ----------------------------------------------------------------------------------------------------------------------
# ------------------------------------------ Set up project compiler definitions ---------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

target_compile_definitions(UntitledImGuiFramework PRIVATE "UIMGUI_COMPILE_LIB" "YAML_CPP_DLL"
        "UVK_LOG_EXPORT_FROM_LIBRARY" "UVK_LIB_COMPILE" "URLL_USE_FUNCTIONAL")
target_compile_definitions(UntitledImageViewer PRIVATE "UVK_LOG_EXPORT_FROM_LIBRARY" "URLL_USE_FUNCTIONAL")

# ----------------------------------------------------------------------------------------------------------------------
# --------------------------------------------- Link to the required libraries -----------------------------------------
# ----------------------------------------------------------------------------------------------------------------------

if (WIN32)
    target_link_libraries(UntitledImGuiFramework glfw opengl32 libglew_static yaml-cpp)
    target_link_libraries(UntitledImageViewer UntitledImGuiFramework yaml-cpp)
else()
    target_link_libraries(UntitledImGuiFramework glfw GLEW OpenGL util pthread yaml-cpp dl)
    target_link_libraries(UntitledImageViewer UntitledImGuiFramework yaml-cpp dl util)

    if (USE_OS_MODULE)
        if (ENABLE_DBUS_UTILS)
            target_link_libraries(UntitledImGuiFramework ${DBUS_LIBRARIES})
        endif()
        if (ENABLE_NOTIFICATIONS)
            target_link_libraries(UntitledImGuiFramework ${DBUS_LIBRARIES})
        endif()
        if (ENABLE_POLKIT_UTILS)

        endif()
        if (ENABLE_UFONT_UTILS)
            target_link_libraries(UntitledImGuiFramework Fontconfig::Fontconfig)
        endif()
    endif()
    if (USE_AVIF_SUPPORT)
        target_link_libraries(UntitledImageViewer avif)
    endif()

    if (USE_JPEG_XL_SUPPORT)
        target_link_libraries(UntitledImageViewer jxl)
    endif()

    if (USE_WEBP_SUPPORT)
        target_link_libraries(UntitledImageViewer webp)
    endif()
endif()

# ----------------------------------------------------------------------------------------------------------------------
# ----------------------------------------------------------- EOF ------------------------------------------------------
# ----------------------------------------------------------------------------------------------------------------------