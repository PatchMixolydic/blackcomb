cmake_minimum_required(VERSION 3.9)
project(blackcomb)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_INC_DIRECTORY "/usr/include" CACHE FILEPATH "GLFW's include directory")

include_directories(${GLFW_INC_DIRECTORY}/GLFW thirdparty/ ${PROJECT_SOURCE_DIR}/include)

add_library(blackcomb thirdparty/glad.c src/renderer/Window.cpp include/blackcomb/renderer/Window.h src/renderer/Shader.cpp include/blackcomb/renderer/Shader.h src/renderer/Mesh.cpp include/blackcomb/renderer/Mesh.h src/renderer/Texture.cpp include/blackcomb/renderer/Texture.h include/blackcomb/misc/EngineException.h src/misc/EngineException.cpp src/renderer/Model.cpp include/blackcomb/renderer/Model.h src/entities/Entity.cpp include/blackcomb/entities/Entity.h src/entities/RenderableEntity.cpp include/blackcomb/entities/RenderableEntity.h src/entities/Camera.cpp include/blackcomb/entities/Camera.h src/entities/FreeMoveCamera.cpp include/blackcomb/entities/FreeMoveCamera.h src/input/MouseWatcher.cpp include/blackcomb/input/MouseWatcher.h src/misc/BlackcombUtils.cpp include/blackcomb/misc/BlackcombUtils.h src/renderer/TextureAtlas.cpp include/blackcomb/renderer/TextureAtlas.h include/blackcomb/misc/Coords.h src/misc/Coords.cpp)