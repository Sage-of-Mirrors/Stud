#pragma once

#include <stdint.h>
#include <vector>
#include <string>

namespace bStream
{
    class CStream;
}

namespace stud
{
    namespace io
    {
        /* Represents the binary information of an individual actor. */
        class CObjectBinary
        {
            /* Header variables. */
            uint32_t mActorSize; // 0x00
            uint32_t mType;      // 0x04
            uint32_t mNameSize;  // 0x08
            std::string mName;   // 0x0C

            /* List of the binary paragraph data that was loaded from file. */
            std::vector<void*> mParagraphs;

            bool readFunctionValueObject(bStream::CStream* stream);
            bool readObject(bStream::CStream* stream);

        public:
            CObjectBinary();

            /* Loads the binary data from the given stream. */
            bool read(bStream::CStream* stream);
        };
    } // End io
} // End stud