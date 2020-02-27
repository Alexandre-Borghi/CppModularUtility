#include "GL/glew.h"

#include "CMU/GL/GFX.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "CMU/GL/Log/Utils.h"

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            Shader::Shader(const std::string& filepath)
                : m_Filepath(filepath), m_RendererID(0)
            {
                ShaderProgramSource source = ParseShader(filepath);
                m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
            }

            Shader::~Shader()
            {
                GLCall(glDeleteProgram(m_RendererID));
            }

            void Shader::Bind() const
            {
                GLCall(glUseProgram(m_RendererID));
            }

            void Shader::Unbind() const
            {
                GLCall(glUseProgram(0));
            }


            void Shader::SetUniform1f(const std::string& name, float f0)
            {
                GLCall(glUniform1f(GetUniformLocation(name), f0));
            }
            
            void Shader::SetUniform2f(const std::string& name, float f0, float f1)
            {
                GLCall(glUniform2f(GetUniformLocation(name), f0, f1));
            }

            void Shader::SetUniform3f(const std::string& name, float f0, float f1, float f2)
            {
                GLCall(glUniform3f(GetUniformLocation(name), f0, f1, f2));
            }

            void Shader::SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3)
            {
                GLCall(glUniform4f(GetUniformLocation(name), f0, f1, f2, f3));
            }


            void Shader::SetUniform1i(const std::string& name, int i0)
            {
                GLCall(glUniform1i(GetUniformLocation(name), i0));
            }
            
            void Shader::SetUniform2i(const std::string& name, int i0, int i1)
            {
                GLCall(glUniform2i(GetUniformLocation(name), i0, i1));
            }

            void Shader::SetUniform3i(const std::string& name, int i0, int i1, int i2)
            {
                GLCall(glUniform3i(GetUniformLocation(name), i0, i1, i2));
            }

            void Shader::SetUniform4i(const std::string& name, int i0, int i1, int i2, int i3)
            {
                GLCall(glUniform4i(GetUniformLocation(name), i0, i1, i2, i3));
            }


            void Shader::SetUniform1ui(const std::string& name, unsigned int ui0)
            {
                GLCall(glUniform1i(GetUniformLocation(name), ui0));
            }
            
            void Shader::SetUniform2ui(const std::string& name, unsigned int ui0, unsigned int ui1)
            {
                GLCall(glUniform2i(GetUniformLocation(name), ui0, ui1));
            }

            void Shader::SetUniform3ui(const std::string& name, unsigned int ui0, unsigned int ui1, unsigned int ui2)
            {
                GLCall(glUniform3i(GetUniformLocation(name), ui0, ui1, ui2));
            }

            void Shader::SetUniform4ui(const std::string& name, unsigned int ui0, unsigned int ui1, unsigned int ui2, unsigned int ui3)
            {
                GLCall(glUniform4i(GetUniformLocation(name), ui0, ui1, ui2, ui3));
            }


            void Shader::SetUniform1fv(const std::string& name, unsigned int count, const float* value)
            {
                GLCall(glUniform1fv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform2fv(const std::string& name, unsigned int count, const float* value)
            {
                GLCall(glUniform2fv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform3fv(const std::string& name, unsigned int count, const float* value)
            {
                GLCall(glUniform3fv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform4fv(const std::string& name, unsigned int count, const float* value)
            {
                GLCall(glUniform4fv(GetUniformLocation(name), count, value));
            }


            void Shader::SetUniform1iv(const std::string& name, unsigned int count, const int* value)
            {
                GLCall(glUniform1iv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform2iv(const std::string& name, unsigned int count, const int* value)
            {
                GLCall(glUniform2iv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform3iv(const std::string& name, unsigned int count, const int* value)
            {
                GLCall(glUniform3iv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform4iv(const std::string& name, unsigned int count, const int* value)
            {
                GLCall(glUniform4iv(GetUniformLocation(name), count, value));
            }


            void Shader::SetUniform1uiv(const std::string& name, unsigned int count, const unsigned int* value)
            {
                GLCall(glUniform1uiv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform2uiv(const std::string& name, unsigned int count, const unsigned int* value)
            {
                GLCall(glUniform2uiv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform3uiv(const std::string& name, unsigned int count, const unsigned int* value)
            {
                GLCall(glUniform3uiv(GetUniformLocation(name), count, value));
            }

            void Shader::SetUniform4uiv(const std::string& name, unsigned int count, const unsigned int* value)
            {
                GLCall(glUniform4uiv(GetUniformLocation(name), count, value));
            }


            void Shader::SetUniformMatrix2fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix2fv(GetUniformLocation(name), count, (char)transpose, value));
            }

            void Shader::SetUniformMatrix3fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix2fv(GetUniformLocation(name), count, (char)transpose, value));
            }

            void Shader::SetUniformMatrix4fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix2fv(GetUniformLocation(name), count, (char)transpose, value));
            }


            void Shader::SetUniformMatrix2x3fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix2x3fv(GetUniformLocation(name), count, (char)transpose, value));
            }

            void Shader::SetUniformMatrix3x2fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix3x2fv(GetUniformLocation(name), count, (char)transpose, value));
            }

            void Shader::SetUniformMatrix2x4fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix2x4fv(GetUniformLocation(name), count, (char)transpose, value));
            }

            void Shader::SetUniformMatrix4x2fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix4x2fv(GetUniformLocation(name), count, (char)transpose, value));
            }

            void Shader::SetUniformMatrix3x4fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix3x4fv(GetUniformLocation(name), count, (char)transpose, value));
            }

            void Shader::SetUniformMatrix4x3fv(const std::string& name, unsigned int count, bool transpose, const float* value)
            {
                GLCall(glUniformMatrix4x3fv(GetUniformLocation(name), count, (char)transpose, value));
            }

            ShaderProgramSource Shader::ParseShader(const std::string& filepath)
            {
                std::ifstream stream(filepath);

                enum class ShaderType
                {
                    NONE = -1, VERTEX = 0, FRAGMENT = 1
                };

                std::string line;
                std::stringstream ss[2];
                ShaderType type = ShaderType::NONE;

                while (getline(stream, line))
                {
                    if (line.find("#shader") != std::string::npos)
                    {
                        if (line.find("vertex") != std::string::npos)
                        {
                            type = ShaderType::VERTEX;
                        }
                        else if (line.find("fragment") != std::string::npos)
                        {
                            type = ShaderType::FRAGMENT;
                        }
                    }
                    else
                    {
                        ss[(int)type] << line << '\n';
                    }
                }

                return { ss[0].str(), ss[1].str() };
            }

            unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
            {
                GLCall(unsigned int id = glCreateShader(type));
                const char* src = source.c_str();

                GLCall(glShaderSource(id, 1, &src, nullptr));
                GLCall(glCompileShader(id));

                // Checking if there was any error during shader compilation

                int result;

                GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

                if (result == GL_FALSE)
                {
                    int length;
                    GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

                    char* message = (char*)alloca(length * sizeof(char));
                    GLCall(glGetShaderInfoLog(id, length, &length, message));

                    // TODO: Add better logging when Log module is ready

                    std::cout << "[ERROR] | [CMU:GL:GFX:Shader] | Failed to compile " 
                        << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader : " << message << std::endl;
                    
                    GLCall(glDeleteShader(id));

                    return 0;
                }

                std::cout << "[INFO] | [CMU:GL:GFX:Shader] | " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment")
                    << " shader successfully compiled" << std::endl;

                return id;
            }

            unsigned int Shader::CreateShader(const std::string& vertexShaderSrc, std::string& fragmentShaderSrc)
            {
                GLCall(unsigned int program = glCreateProgram());
                unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShaderSrc);
                unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSrc);

                GLCall(glAttachShader(program, vs));
                GLCall(glAttachShader(program, fs));
                GLCall(glLinkProgram(program));
                GLCall(glValidateProgram(program));

                GLCall(glDeleteShader(vs));
                GLCall(glDeleteShader(fs));

                return program;
            }

            int Shader::GetUniformLocation(const std::string& name)
            {
                if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
                    return m_UniformLocationCache[name];

                GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));

                if (location == -1)
                {
                    std::cout << "[WARNING] | [CMU:GL:GFX:Shader] | Unable to get uniform location of uniform '"
                        << name << "'" << std::endl;
                }

                m_UniformLocationCache[name] = location;

                return location;
            }
        } // namespace GFX

    } // namespace GL

} // namespace CMU