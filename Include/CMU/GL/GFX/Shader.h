#ifndef GFX_SHADER_H
#define GFX_SHADER_H

#include <string>
#include <unordered_map>

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            struct ShaderProgramSource
            {
                std::string VertexSource;
                std::string FragmentSource;
            };
            
            class Shader
            {
            public:
                Shader(const std::string& filepath);
                ~Shader();

                void Bind() const;
                void Unbind() const;


                void SetUniform1f(const std::string& name, float f0);
                void SetUniform2f(const std::string& name, float f0, float f1);
                void SetUniform3f(const std::string& name, float f0, float f1, float f2);
                void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3);

                void SetUniform1i(const std::string& name, int i0);
                void SetUniform2i(const std::string& name, int i0, int i1);
                void SetUniform3i(const std::string& name, int i0, int i1, int i2);
                void SetUniform4i(const std::string& name, int i0, int i1, int i2, int i3);

                void SetUniform1ui(const std::string& name, unsigned int ui0);
                void SetUniform2ui(const std::string& name, unsigned int ui0, unsigned int ui1);
                void SetUniform3ui(const std::string& name, unsigned int ui0, unsigned int ui1, unsigned int ui2);
                void SetUniform4ui(const std::string& name, unsigned int ui0, unsigned int ui1, unsigned int ui2, unsigned int ui3);

                void SetUniform1fv(const std::string& name, unsigned int count, const float* value);
                void SetUniform2fv(const std::string& name, unsigned int count, const float* value);
                void SetUniform3fv(const std::string& name, unsigned int count, const float* value);
                void SetUniform4fv(const std::string& name, unsigned int count, const float* value);

                void SetUniform1iv(const std::string& name, unsigned int count, const int* value);
                void SetUniform2iv(const std::string& name, unsigned int count, const int* value);
                void SetUniform3iv(const std::string& name, unsigned int count, const int* value);
                void SetUniform4iv(const std::string& name, unsigned int count, const int* value);

                void SetUniform1uiv(const std::string& name, unsigned int count, const unsigned int* value);
                void SetUniform2uiv(const std::string& name, unsigned int count, const unsigned int* value);
                void SetUniform3uiv(const std::string& name, unsigned int count, const unsigned int* value);
                void SetUniform4uiv(const std::string& name, unsigned int count, const unsigned int* value);

                void SetUniformMatrix2fv(const std::string& name, unsigned int count, bool transpose, const float* value);
                void SetUniformMatrix3fv(const std::string& name, unsigned int count, bool transpose, const float* value);
                void SetUniformMatrix4fv(const std::string& name, unsigned int count, bool transpose, const float* value);

                void SetUniformMatrix2x3fv(const std::string& name, unsigned int count, bool transpose, const float* value);
                void SetUniformMatrix3x2fv(const std::string& name, unsigned int count, bool transpose, const float* value);
                void SetUniformMatrix2x4fv(const std::string& name, unsigned int count, bool transpose, const float* value);
                void SetUniformMatrix4x2fv(const std::string& name, unsigned int count, bool transpose, const float* value);
                void SetUniformMatrix3x4fv(const std::string& name, unsigned int count, bool transpose, const float* value);
                void SetUniformMatrix4x3fv(const std::string& name, unsigned int count, bool transpose, const float* value);

            private:
                ShaderProgramSource ParseShader(const std::string& filepath);
                unsigned int CompileShader(unsigned int type, const std::string& source);
                unsigned int CreateShader(const std::string& vertexShader, std::string& fragmentShader);
                int GetUniformLocation(const std::string& name);

            private:
                std::string m_Filepath;
                unsigned int m_RendererID;

                std::unordered_map<std::string, int> m_UniformLocationCache;

            private:
                inline unsigned int GetRendererID() const { return m_RendererID; }
            };
        } // namespace GFX
        
    } // namespace GL
    
} // namespace CMU


#endif