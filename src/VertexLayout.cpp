#include "VertexLayout.h"
#include <memory.h>

namespace AKI {

    static const uint8_t s_attribTypeSizeD3D1x[AttribType::Count][4] =
    {
        {  1,  2,  4,  4 }, // Uint8
        {  4,  4,  4,  4 }, // Uint10
        {  2,  4,  8,  8 }, // Int16
        {  2,  4,  8,  8 }, // Half
        {  4,  8, 12, 16 }, // Float
    };

    static const uint8_t s_attribTypeSizeGL[AttribType::Count][4] =
    {
        {  1,  2,  4,  4 }, // Uint8
        {  4,  4,  4,  4 }, // Uint10
        {  2,  4,  6,  8 }, // Int16
        {  2,  4,  6,  8 }, // Half
        {  4,  8, 12, 16 }, // Float
    };

    static const uint8_t (*s_attribTypeSize[])[AttribType::Count][4] =
    {
        &s_attribTypeSizeD3D1x, // Noop
        &s_attribTypeSizeD3D1x, // Direct3D11
        &s_attribTypeSizeD3D1x, // Direct3D12
        &s_attribTypeSizeGL,    // Metal
        &s_attribTypeSizeGL,    // OpenGLES
        &s_attribTypeSizeGL,    // OpenGL
        &s_attribTypeSizeD3D1x, // Vulkan
        &s_attribTypeSizeD3D1x, // WebGPU
        
        &s_attribTypeSizeD3D1x, // Count
    };

    VertexLayout::VertexLayout():m_stride(0)
    {
    }

    VertexLayout& VertexLayout::begin(GraphAPI::Enum type)
    {
        m_hash = type;
        m_stride = 0;
        
        memset(m_attributes, 0, sizeof(m_attributes));
        memset(m_offset, 0, sizeof(m_offset));
        
        return *this;
    }

    void VertexLayout::end()
    {
    //    bx::HashMurmur2A murmur;
    //    murmur.begin();
    //    murmur.add(m_attributes, sizeof(m_attributes) );
    //    murmur.add(m_offset, sizeof(m_offset) );
    //    murmur.add(m_stride);
    //    m_hash = murmur.end();
    }

    VertexLayout& VertexLayout::add(Attrib::Enum attrib, uint8_t num, AttribType::Enum type, bool normalized, bool asInt)
    {
        const uint16_t encodedNum  = (num-1)&3;
        const uint16_t encodedType = (type&7)<<3;
        const uint16_t encodedNorm = (normalized&1)<<7;
        const uint16_t encodeAsInt = (asInt&(!!"\x1\x1\x1\x0\x0"[type]))<<8;
        m_attributes[attrib] = encodedNum|encodedType|encodedNorm|encodeAsInt;
        m_offset[attrib] = m_stride;
        m_stride += (*s_attribTypeSize[m_hash])[type][num-1];
        
        return *this;
    }

    VertexLayout& VertexLayout::skip(uint8_t num)
    {
        m_stride += num;
        
        return *this;
    }

    void VertexLayout::decode(Attrib::Enum attrib, uint8_t& num, AttribType::Enum& type, bool& normalized, bool& asInt) const
    {
        uint16_t val = m_attributes[attrib];
        num        = (val&3)+1;
        type       = AttribType::Enum((val>>3)&7);
        normalized = !!(val&(1<<7));
        asInt      = !!(val&(1<<8));
    }

} // namespace AKI
