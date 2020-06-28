#include "shader.h"

Shader::Shader(const GLchar *vertexPath, const GLchar *fragmentPath)
{
    string vertexCode, fragmentCode;
    ifstream vShaderFile, fShaderFile;
    vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    try
    {
        // 打开文件
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        stringstream vShaderStream, fShaderStream;
        // 读取文件的缓冲内容到数据流中
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // 关闭文件处理器
        vShaderFile.close();
        fShaderFile.close();
        // 转换数据流到string
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(ifstream::failure e)
    {
        cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // 顶点着色器
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    // 打印编译错误（如果有的话）
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
    };
    // 片段着色器
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    // 打印编译错误（如果有的话）
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
    };
    // 着色器程序
    m_ID = glCreateProgram();
    glAttachShader(m_ID, vertex);
    glAttachShader(m_ID, fragment);
    glLinkProgram(m_ID);
    // 打印连接错误（如果有的话）
    glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
        cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
    }

    // 删除着色器，它们已经链接到我们的程序中了，已经不再需要了
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    glDeleteProgram(m_ID);
}

void Shader::use()
{
    glUseProgram(m_ID);
}

void Shader::setBool(const string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value);
}

void Shader::setInt(const string &name, int value) const
{
    glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Shader::setFloat(const string &name, float value) const
{
    glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Shader::setMat4(const string &name, glm::mat4 value) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()),
                       1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setVec3(const string &name, glm::vec3 value) const
{
    glUniform3fv(glGetUniformLocation(m_ID, name.c_str()),
                 1, glm::value_ptr(value));
}

void Shader::setVec3(const string &name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(m_ID, name.c_str()), x, y, z);
}

unsigned int Shader::ID()
{
    return m_ID;
}
