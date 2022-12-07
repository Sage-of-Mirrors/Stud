#pragma once

#include <stdint.h>

namespace stud
{
    namespace constants
    {
        /* File magics */
        const uint32_t STB_MAGIC = 0x53544200; // Magic for studio binary file

        /* Object magics */
        const uint32_t JFVB_MAGIC = 0x4A465642; // Magic for function value object
        const uint32_t JACT_MAGIC = 0x4A414354; // Magic for actor object
        const uint32_t JSND_MAGIC = 0x4A534E44; // Magic for sound object
        const uint32_t JPTC_MAGIC = 0x4A505443; // Magic for particle object
        const uint32_t JCMR_MAGIC = 0x4A434D52; // Magic for camera object
        const uint32_t JMSG_MAGIC = 0x4A4D5347; // Magic for message object
        const uint32_t CONTROL_MAGIC = 0xFFFFFFFF; // Magic for control object
    }
}
