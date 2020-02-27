#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            class VertexArray
            {
            public:
                VertexArray();
                ~VertexArray();

                void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

                void Bind() const;
                void Unbind() const;
                
            private:
                unsigned int m_RendererID;
                
            };
        }
    }
}

#endif