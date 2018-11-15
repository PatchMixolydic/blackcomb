#include <fstream>
#include <iostream>
#include <sstream>
#include <assert.h>
#include "blackcomb/renderer/Shader.h"
#include "blackcomb/misc/EngineException.h"

Shader::Shader(std::string vertexFilename, std::string fragmentFilename) {
    GLuint vertexShader = loadAndCompileShader(GL_VERTEX_SHADER, vertexFilename);
    reportCompileStatus(GL_VERTEX_SHADER, vertexShader);
    GLuint fragmentShader = loadAndCompileShader(GL_FRAGMENT_SHADER, fragmentFilename);
    reportCompileStatus(GL_FRAGMENT_SHADER, fragmentShader);

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    reportLinkStatus(program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::bind() {
    glUseProgram(program);
}

void Shader::unbind() {
    glUseProgram(0);
}

GLuint Shader::loadAndCompileShader(unsigned int shaderType, std::string filename) {
    std::ifstream shaderFile(filename);
    std::string shaderSource(std::istreambuf_iterator<char>(shaderFile), {});
    const char* shaderSourceCStr = shaderSource.c_str();
    GLuint shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderSourceCStr, nullptr);
    glCompileShader(shaderId);
    return shaderId;
}

void Shader::reportCompileStatus(GLuint shaderType, GLuint shader) {
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Error compiling " << getShaderName(shaderType) << ": " << infoLog << std::endl;
    }
}

void Shader::reportLinkStatus(GLuint program) {
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "Error linking program: " << infoLog << std::endl;
    }
}

void Shader::setUniformInt(const char *name, int val) {
    GLint loc = glGetUniformLocation(program, name);
    glUniform1i(loc, val);
}

void Shader::setUniformFloat(const char* name, float val) {
    GLint loc = glGetUniformLocation(program, name);
    glUniform1f(loc, val);
}

void Shader::setUniformDouble(const char* name, double val) {
    GLint loc = glGetUniformLocation(program, name);
    glUniform1d(loc, val);
}

void Shader::setUniformVecF(const char* name, std::vector<float> val) {
    setUniformVecF(name, val.data(), val.size());
}

void Shader::setUniformVecF(const char* name, float* val, size_t size) {
    GLint loc = glGetUniformLocation(program, name);
    switch (size) {
        case 1:
            glUniform1f(loc, val[0]);
        case 2:
            glUniform2f(loc, val[0], val[1]);
        case 3:
            glUniform3f(loc, val[0], val[1], val[2]);
        case 4:
            glUniform4f(loc, val[0], val[1], val[2], val[3]);
        default:
            char msg[64];
            snprintf(msg, 64, "Can't create a uniform Vec%i", (int)size);
            throw EngineException(msg);
    }
}

void Shader::setUniformMat4F(const char* name, GLfloat* value, GLboolean transpose) {
    GLint loc = glGetUniformLocation(program, name);
    glUniformMatrix4fv(loc, 1, transpose, value);
}
