#ifndef Buffers_h
#define Buffers_h

#include "VertexLayout.h"

namespace AKI {

    struct IndexBufferStatic
    {
        std::string m_name;
        uint32_t    m_size;
    };

    struct VertexBufferStatic
    {
        std::string m_name;
        uint32_t    m_size;
        uint16_t    m_stride;
    };

    struct IndexBufferDynamic
    {
        std::shared_ptr<IndexBufferStatic*> m_buffer;
        uint32_t m_offset;
        uint32_t m_size;
        uint32_t m_startIndex;
        uint16_t m_flags;
    };

    struct VertexBufferDynamic
    {
        std::shared_ptr<VertexBufferStatic*> m_buffer;
        std::shared_ptr<VertexLayout*> m_layout;
        uint32_t m_offset;
        uint32_t m_size;
        uint32_t m_startVertex;
        uint32_t m_numVertices;
        uint16_t m_stride;
        uint16_t m_flags;
    };


} // namespace AKI

#endif /* Buffers_h */
