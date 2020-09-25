#ifndef VERTEXLAYOUT_H
#define VERTEXLAYOUT_H

#include "Common.h"

namespace AKI {

    // Corresponds to vertex shader attribute.
    namespace Attrib
    {
        enum Enum
        {
            Position,  //!< a_position
            Normal,    //!< a_normal
            Tangent,   //!< a_tangent
            Bitangent, //!< a_bitangent
            Color0,    //!< a_color0
            Color1,    //!< a_color1
            Color2,    //!< a_color2
            Color3,    //!< a_color3
            Indices,   //!< a_indices
            Weight,    //!< a_weight
            TexCoord0, //!< a_texcoord0
            TexCoord1, //!< a_texcoord1
            TexCoord2, //!< a_texcoord2
            TexCoord3, //!< a_texcoord3
            TexCoord4, //!< a_texcoord4
            TexCoord5, //!< a_texcoord5
            TexCoord6, //!< a_texcoord6
            TexCoord7, //!< a_texcoord7
            
            Count
        };
    }; // namespace Attrib

    namespace AttribType
    {
        enum Enum
        {
            Uint8,  //!< Uint8
            Uint10, //!< Uint10
            Int16,  //!< Int16
            Half,   //!< Half
            Float,  //!< Float
            
            Count
        };
    }; // namespace AttribType

    class VertexLayout
    {
    public:
        VertexLayout();
        VertexLayout& begin(GraphAPI::Enum type = GraphAPI::Noop);
        void end();
        
        /// @param num
        ///   Number of elements 1, 2, 3 or 4.
        /// @param normalized
        ///   When using fixed point AttribType (f.e. Uint8)
        ///   value will be normalized for vertex shader usage. When normalized
        ///   is set to true, AttribType::Uint8 value in range 0-255 will be
        ///   in range 0.0-1.0 in vertex shader.
        /// @param asInt
        ///   Packaging rule for vertexPack, vertexUnpack, and
        ///   vertexConvert for AttribType::Uint8 and AttribType::Int16.
        ///   Unpacking code must be implemented inside vertex shader.
        VertexLayout& add(
                          Attrib::Enum attrib,
                          uint8_t num,
                          AttribType::Enum type,
                          bool normalized = false,
                          bool asInt = false
                          );
        
        // Skip num bytes in vertex stream.
        VertexLayout& skip(uint8_t num);
        
        // Decode attribute.
        void decode(
                    Attrib::Enum attrib,
                    uint8_t& num,
                    AttribType::Enum& type,
                    bool& normalized,
                    bool& asInt
                    ) const;
        
        bool has(Attrib::Enum attrib) const { return UINT16_MAX != m_attributes[attrib]; }
        
        uint16_t getOffset(Attrib::Enum attrib) const { return m_offset[attrib]; }
        uint16_t getStride() const { return m_stride; }
        uint32_t getSize(uint32_t num) const { return num*m_stride; }
        
    private:
        uint32_t m_hash;
        uint16_t m_stride;
        uint16_t m_offset[Attrib::Count];
        uint16_t m_attributes[Attrib::Count];
    };

} // namespace AKI

#endif // VERTEXLAYOUT_H
