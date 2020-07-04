#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>  // 包含glad来获取所有的必须OpenGL头文件
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;

class Shader
{
public:
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    ~Shader();

    // 使用/激活程序
    void use();
    // uniform工具函数
    void setBool(const string &name, bool value) const;
    void setInt(const string &name, int value) const;
    void setFloat(const string &name, float value) const;
    void setMat4(const string &name, glm::mat4 value) const;
    void setVec3(const string &name, glm::vec3 value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    unsigned int ID();
private:
    // 程序ID
    unsigned int m_ID;
};

#endif // SHADER_H
