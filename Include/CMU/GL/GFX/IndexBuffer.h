#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

namespace CMU
{
    namespace GL
    {
        namespace GFX
        {
            class IndexBuffer
            {
            public:
                IndexBuffer(const unsigned int* data, unsigned int count);
                ~IndexBuffer();

                void Bind() const;
                void Unbind() const;

            private:
                unsigned int m_RendererID;
                unsigned int m_Count;

            public:
                inline unsigned int GetRendererID() { return m_RendererID; }
                inline unsigned int GetCount() { return m_Count; }
            };
        }
    }
}

#endif