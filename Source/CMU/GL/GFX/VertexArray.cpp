#include "CMU/GL/GFX/VertexArray.h"

#include "CMU/GL/GLUtils.h"
#include "CMU/GL/Log/Utils.h"

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            VertexArray::VertexArray()
            {
                GLCall(glGenVertexArrays(1, &m_RendererID));
            }


            VertexArray::~VertexArray()
            {
                GLCall(glDeleteVertexArrays(1, &m_RendererID));
            }


            void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
            {
                Bind();
                vb.Bind();

                const auto& elements = layout.GetElements();
                unsigned long int offset = 0; // Long int because a void* is 8 bytes

                for (unsigned int i = 0; i < elements.size(); i++)
                {
                    auto& element = elements[i];
                    GLCall(glEnableVertexAttribArray(i));
                    GLCall(glVertexAttribPointer(i, element.Count, element.Type, element.Normalized, layout.GetStride(), (const void*)offset));
                    offset += element.Count * CMU::GL::GetSizeOfType(element.Type);
                }
            }


            void VertexArray::Bind() const
            {
                GLCall(glBindVertexArray(m_RendererID));
            }


            void VertexArray::Unbind() const
            {
                GLCall(glBindVertexArray(0));
            }
        }
    }
}