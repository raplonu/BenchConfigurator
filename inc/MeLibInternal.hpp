#ifndef ME_LIB_INTERNAL_HPP
#define ME_LIB_INTERNAL_HPP

namespace melib {
    template<int N>
    void copy(int * dst, const int * src, int elemNb) {
        static_assert(N >= 1, "N cannot be under 1");
        
        int i{};

        if constexpr (N > 1) {
            for(; i < elemNb / N; ++i)
                for(int j{}; j < N; ++j)
                    dst[i * N + j] = src[i * N + j];

            i *= N;
        }

        for(; i < elemNb; ++i)
            dst[i] = src[i];
    }
}

#endif