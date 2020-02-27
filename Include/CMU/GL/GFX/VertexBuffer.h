#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            class VertexBuffer
            {
            public:
                VertexBuffer(const void* data, unsigned int size);
                ~VertexBuffer();

                void Bind() const;
                void Unbind() const;

            private:
                unsigned int m_RendererID;

            public:
                inline unsigned int GetRendererID() { return m_RendererID; }
            };
        }
    }
}

#endif