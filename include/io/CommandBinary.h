#pragma once

#include <stdint.h>
#include <vector>

namespace stud
{
    namespace io
    {
        /* Represents the binary information of a single command. */
        struct FCommandBinary
        {
            uint16_t mArgumentSize;
            uint16_t mCommandAndUpdateMode;

            std::vector<uint8_t> mArgumentBytes;

        public:
            FCommandBinary();
        };
    } // End io
} // End stud