#include "CMU/GL/GFX/IndexBuffer.h"

#include "GL/glew.h"

#include "CMU/GL/Log/Utils.h"

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
                :m_Count(count)
            {
                GLCall(glGenBuffers(1, &m_RendererID));
                GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
                GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
            }

            IndexBuffer::~IndexBuffer()
            {
                GLCall(glDeleteBuffers(1, &m_RendererID));
            }

            void IndexBuffer::Bind() const
            {
                GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
            }

            void IndexBuffer::Unbind() const
            {
                GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
            }
        } // namespace GFX
        
    } // namespace GL
    
} // namespace CMU