#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdint.h>
#include <string>
#include "Utils.h"

namespace AKI {

    namespace GraphAPI
    {
      enum Enum
      {
        Noop,         //!< No graph.
        Direct3D11,   //!< Direct3D 11.0
        Direct3D12,   //!< Direct3D 12.0
        Metal,        //!< Metal
        OpenGLES,     //!< OpenGL ES 2.0+
        OpenGL,       //!< OpenGL 2.1+
        Vulkan,       //!< Vulkan
        WebGPU,       //!< WebGPU

        Count
      };
    }; // namespace GraphAPI

} // namspace AKI

#endif // COMMON_H
