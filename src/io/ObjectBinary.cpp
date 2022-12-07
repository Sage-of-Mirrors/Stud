#include "io/ObjectBinary.h"

#include "bStream/bstream.h"
#include "Constants.h"

#include <iostream>

stud::io::CObjectBinary::CObjectBinary() : mActorSize(0), mType(0), mNameSize(0), mName("")
{

}

bool stud::io::CObjectBinary::read(bStream::CStream* stream)
{
    // Read header
    try
    {
        mActorSize = stream->readUInt32();
        mType = stream->readUInt16();
    }
    catch (std::exception e)
    {
        std::cout << "Failed to read object binary, offset " << stream->tell() << std::endl;
        return false;
    }

    bool bResult = false;

    // The function value object (FVB) has a format distinct from the other object types.
    if (mType == constants::JFVB_MAGIC)
    {
        bResult = readFunctionValueObject(stream);
    }
    else
    {
        bResult = readObject(stream);
    }

    return bResult;
}

bool stud::io::CObjectBinary::readFunctionValueObject(bStream::CStream* stream)
{
    return true;
}

bool stud::io::CObjectBinary::readObject(bStream::CStream* stream)
{
    return true;
}
