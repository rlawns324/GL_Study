#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>
#pragma warning(disable:4996)
using namespace std;
using std::ifstream;
using std::string;

// Create a NULL-terminated string by reading the provided file
static char* readShaderSource(const char* shaderFile)
{
    string VertexShaderCode;
    ifstream VertexShaderStream(shaderFile, std::ios::in);
    if (VertexShaderStream.is_open()) {
        std::string Line = "";
        while (getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }
    else {
        cout << "Impossible to open" << shaderFile << endl;
        getchar();
        return 0;
    }
    char* buf = new char[VertexShaderCode.length() + 1];
    strcpy(buf, VertexShaderCode.c_str());
    return buf;
}

GLuint LoadShaders(const char*  vsource, const char*  fsource)
{
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;

    static const GLchar* vertex_shader_source = readShaderSource(vsource);
    static const GLchar* fragment_shader_source = readShaderSource(fsource);

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, (const GLchar**)&vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, (const GLchar**)&fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    /*  Error Check */
    GLint compiled;
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        cerr << "Vertex shader failed to compile:" << endl;
        char* logMsg = new char[100];
        glGetShaderInfoLog(vertex_shader, 100, NULL, logMsg);
        cerr << logMsg << endl; delete[] logMsg;// exit (EXIT_FAILURE);
    }

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        cerr << "fragment shader failed to compile:" << endl;
        char* logMsg = new char[100];
        glGetShaderInfoLog(fragment_shader, 100, NULL, logMsg);
        cerr << logMsg << endl; delete[] logMsg;// exit (EXIT_FAILURE);
    }

    /* Delete dynamic variables */
    delete[] vertex_shader_source;
    delete[] fragment_shader_source;
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;
}
