cmake_minimum_required(VERSION 3.9)
project(blackcomb)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_INC_DIRECTORY "/usr/include" CACHE FILEPATH "GLFW's include directory")

include_directories(${GLFW_INC_DIRECTORY}/GLFW thirdparty/ include/ include/blackcomb/imgui)

add_library(blackcomb thirdparty/glad.c src/base/Window.cpp include/blackcomb/base/Window.h src/renderer/Shader.cpp include/blackcomb/renderer/Shader.h src/renderer/Mesh.cpp include/blackcomb/renderer/Mesh.h src/renderer/Texture.cpp include/blackcomb/renderer/Texture.h include/blackcomb/misc/BlackcombException.h src/misc/BlackcombException.cpp src/renderer/Model.cpp include/blackcomb/renderer/Model.h src/entities/BaseEntity.cpp include/blackcomb/entities/BaseEntity.h src/entities/RenderableEntity.cpp include/blackcomb/entities/RenderableEntity.h src/entities/Camera.cpp include/blackcomb/entities/Camera.h src/entities/FreeMoveCamera.cpp include/blackcomb/entities/FreeMoveCamera.h src/input/MouseWatcher.cpp include/blackcomb/input/MouseWatcher.h src/misc/BlackcombUtils.cpp include/blackcomb/misc/BlackcombUtils.h src/renderer/TextureAtlas.cpp include/blackcomb/renderer/TextureAtlas.h include/blackcomb/misc/Coords.h src/misc/Coords.cpp src/misc/RNG.cpp include/blackcomb/misc/RNG.h src/base/AppBase.cpp include/blackcomb/base/AppBase.h
        src/imgui/imgui.cpp src/imgui/imgui_draw.cpp src/imgui/imgui_widgets.cpp src/imgui/imgui_impl_glfw.cpp src/imgui/imgui_impl_opengl3.cpp src/imgui/imgui_demo.cpp
        src/imgui/Wrapper.cpp include/blackcomb/imgui/Wrapper.h)