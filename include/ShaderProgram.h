#ifndef ShaderProgram_h
#define ShaderProgram_h

#include "Common.h"

namespace AKI {

    namespace UniformType
    {
        enum Enum
        {
            Sampler, //!< Sampler.
            End,     //!< Reserved, do not use.

            Vec4,    //!< 4 floats vector.
            Mat3,    //!< 3x3 matrix.
            Mat4,    //!< 4x4 matrix.

            Count
        };
    }; // namespace UniformType

    namespace Topology
    {
        /// Primitive topology:
        enum Enum
        {
            TriList,   //!< Triangle list.
            TriStrip,  //!< Triangle strip.
            LineList,  //!< Line list.
            LineStrip, //!< Line strip.
            PointList, //!< Point list.

            Count
        };
    }; // namespace Topology

    namespace TopologySort
    {
        /// Topology sort order:
        enum Enum
        {
            DirectionFrontToBackMin, //!<
            DirectionFrontToBackAvg, //!<
            DirectionFrontToBackMax, //!<
            DirectionBackToFrontMin, //!<
            DirectionBackToFrontAvg, //!<
            DirectionBackToFrontMax, //!<
            DistanceFrontToBackMin,  //!<
            DistanceFrontToBackAvg,  //!<
            DistanceFrontToBackMax,  //!<
            DistanceBackToFrontMin,  //!<
            DistanceBackToFrontAvg,  //!<
            DistanceBackToFrontMax,  //!<

            Count
        };
    }; // namespace TopologySort

    class ShaderProgram {
        
    };

} // namspace AKI


#endif /* ShaderProgram_h */
