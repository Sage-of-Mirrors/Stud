#pragma once

#include <stdint.h>
#include <vector>

namespace bStream
{
    class CStream;
}

namespace stud
{
    namespace io
    {
        class CObjectBinary;

        /* Represents the binary information (JACT, FVB, etc.) stored within an STB file. */
        class CStudioBinary
        {
            /* Header variables. */
            uint32_t mMagic;       // 0x00
            uint16_t mEndianness;  // 0x04
            uint16_t mUnknown1;    // 0x06
            uint32_t mFileSize;    // 0x08
            uint32_t mActorCount;  // 0x0C
            uint8_t mWatermark[8]; // 0x10
            uint32_t mUnknown2;    // 0x18
            uint32_t mUnknown3;    // 0x1C

            /* List of the binary object data that was loaded from the file. */
            std::vector<CObjectBinary*> mObjects;

        public:
            CStudioBinary();

            /* Loads the binary data from the given stream. */
            bool read(bStream::CStream* stream);
        };
    } // End io
} // End stud
