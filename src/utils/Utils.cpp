#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>

namespace AKI {

    void Assert(bool isSuccessed, const char* message)
    {
        if (!isSuccessed) {
            printf("Fatal: %s, line %d %s\n",__FILE__, __LINE__, message);
            abort();
        }
    }

} // namspace AKI
