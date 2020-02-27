#ifndef VERTEX_BUFFER_LAYOUT_H
#define VERTEX_BUFFER_LAYOUT_H

#include <vector>

#include "GL/glew.h"

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            struct VertexBufferElement
            {
                unsigned int  Count;
                unsigned int  Type;
                unsigned char Normalized;
            };

            class VertexBufferLayout
            {
            public:
                VertexBufferLayout();
                ~VertexBufferLayout();

                void Push(unsigned int type, unsigned int count, unsigned char normalized);

            private:
                std::vector<VertexBufferElement> m_Elements;
                int m_Stride;

            public:
                inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
                inline int GetStride() const { return m_Stride; }
            };
        }
    }
}

#endif