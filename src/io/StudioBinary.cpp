#include "io/StudioBinary.h"

#include "io/ObjectBinary.h"
#include "bStream/bStream.h"
#include "Constants.h"

#include <iostream>

stud::io::CStudioBinary::CStudioBinary() : mMagic(0), mEndianness(0), mUnknown1(0), mFileSize(0),
  mActorCount(0), mWatermark(), mUnknown2(0), mUnknown3(0)
{

}

bool stud::io::CStudioBinary::read(bStream::CStream* stream)
{
    // Read header
    try
    {
        mMagic = stream->readUInt32();
        mEndianness = stream->readUInt16();
        mUnknown1 = stream->readUInt16();
        mFileSize = stream->readUInt32();
        mActorCount = stream->readUInt32();

        stream->readBytesTo(mWatermark, 8);

        mUnknown2 = stream->readUInt32();
        mUnknown3 = stream->readUInt32();
    }
    catch (std::exception e)
    {
        std::cout << "Failed to read studio binary header, offset " << stream->tell() << std::endl;
        return false;
    }

    // Basic validation
    if (mMagic != constants::STB_MAGIC)
    {
        std::cout << "Incorrect studio binary magic! (" << mMagic << ")" << std::endl;
        return false;
    }

    // Read actors
    bool bActorReadError = false;
    for (int i = 0; i < mActorCount; i++)
    {
        CObjectBinary* object = new CObjectBinary();

        if (!object->read(stream))
        {
            bActorReadError = true;
            break;
        }

        mObjects.push_back(object);
    }

    return !bActorReadError;
}
