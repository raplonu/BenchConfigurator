#include <MeLib.hpp>
#include <MeLibInternal.hpp>
#include <config.hpp>

namespace melib {
    void copy(int * dst, const int * src, int elemNb) {
        copy<NB>(dst, src, elemNb);
    }
}