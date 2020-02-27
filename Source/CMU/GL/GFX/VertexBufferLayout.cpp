#include "CMU/GL/GFX/VertexBufferLayout.h"

#include "CMU/GL/GLUtils.h"

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            VertexBufferLayout::VertexBufferLayout()
                : m_Stride(0)
            {
            }

            VertexBufferLayout::~VertexBufferLayout()
            {
            }

            void VertexBufferLayout::Push(unsigned int type, unsigned int count, unsigned char normalized)
            {
                m_Elements.push_back({ count, type, normalized });
                m_Stride += count * CMU::GL::GetSizeOfType(type);
            }
        }
    }
}