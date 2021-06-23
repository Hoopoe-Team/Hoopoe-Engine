#ifndef __HOOPOE_ENGINE_CORE_EXCEPTION_H__
#define __HOOPOE_ENGINE_CORE_EXCEPTION_H__

#include <exception>

#include "Types.h"

namespace Hoopoe 
{

class Exception : public std::exception 
{
public:
    enum ExceptionCodes 
    {
        ERR_CANNOT_WRITE_TO_FILE,
        ERR_INVALID_STATE,
        ERR_INVALIDPARAMS,
        ERR_RENDERINGAPI_ERROR,
        ERR_DUPLICATE_ITEM,
        ERR_ITEM_NOT_FOUND = ERR_DUPLICATE_ITEM,
        ERR_FILE_NOT_FOUND,
        ERR_INTERNAL_ERROR,
        ERR_RT_ASSERTION_FAILED,
        ERR_NOT_IMPLEMENTED,
        ERR_INVALID_CALL
    };

    Exception(int number, const String& description, const String& source);
    Exception(int number, const String& description, const String& source, const char* type, const char* file, long line);
    Exception(const Exception& rhs);

    ~Exception() throw() {}

    const String &getFullDescription(void) const { return fullDesc; }
    const String &getSource() const { return source; }
    const char* getFile() const { return file; }
    long getLine() const { return line; }
    const String &getDescription(void) const { return description; }
    const char* what() const throw() { return fullDesc.c_str(); }

    
protected:
    long line;
    const char* typeName;
    String description;
    String source;
    const char* file;
    String fullDesc; // storage for char* returned by what()
private:

};

class UnimplementedException : public Exception 
{
public:
    UnimplementedException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class FileNotFoundException : public Exception
{
public:
    FileNotFoundException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class IOException : public Exception
{
public:
    IOException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class InvalidStateException : public Exception
{
public:
    InvalidStateException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class InvalidParametersException : public Exception
{
public:
    InvalidParametersException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class ItemIdentityException : public Exception
{
public:
    ItemIdentityException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class InternalErrorException : public Exception
{
public:
    InternalErrorException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class RenderingAPIException : public Exception
{
public:
    RenderingAPIException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class RuntimeAssertionException : public Exception
{
public:
    RuntimeAssertionException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class InvalidCallException : public Exception
{
public:
    InvalidCallException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inNumber, inDescription, inSource, __FUNCTION__, inFile, inLine) {}
};

class ExceptionFactory
{
private:
    /// Private constructor, no construction
    ExceptionFactory() {}
    static void _throwException(
        Exception::ExceptionCodes code, int number,
        const String& desc, 
        const String& src, const char* file, long line)
    {
        switch (code)
        {
        case Exception::ERR_CANNOT_WRITE_TO_FILE:   throw IOException(number, desc, src, file, line);
        case Exception::ERR_INVALID_STATE:          throw InvalidStateException(number, desc, src, file, line);
        case Exception::ERR_INVALIDPARAMS:          throw InvalidParametersException(number, desc, src, file, line);
        case Exception::ERR_RENDERINGAPI_ERROR:     throw RenderingAPIException(number, desc, src, file, line);
        case Exception::ERR_DUPLICATE_ITEM:         throw ItemIdentityException(number, desc, src, file, line);
        case Exception::ERR_FILE_NOT_FOUND:         throw FileNotFoundException(number, desc, src, file, line);
        case Exception::ERR_INTERNAL_ERROR:         throw InternalErrorException(number, desc, src, file, line);
        case Exception::ERR_RT_ASSERTION_FAILED:    throw RuntimeAssertionException(number, desc, src, file, line);
        case Exception::ERR_NOT_IMPLEMENTED:        throw UnimplementedException(number, desc, src, file, line);
        case Exception::ERR_INVALID_CALL:           throw InvalidCallException(number, desc, src, file, line);
        default:                                    throw Exception(number, desc, src, "Exception", file, line);
        }
    }
public:
    static void throwException(
        Exception::ExceptionCodes code,
        const String& desc,
        const String& src, const char* file, long line)
    {
        _throwException(code, code, desc, src, file, line);
    }
};

}

#ifndef HE_EXCEPT
#define HE_EXCEPT_3(code, desc, src)  Hoopoe::ExceptionFactory::throwException(code, desc, src, __FILE__, __LINE__)
#define HE_EXCEPT_2(code, desc)       Hoopoe::ExceptionFactory::throwException(code, desc, __FUNCTION__, __FILE__, __LINE__)
#define HE_EXCEPT_CHOOSER(arg1, arg2, arg3, arg4, ...) arg4
#define HE_EXPAND(x) x // MSVC workaround
#define HE_EXCEPT(...) HE_EXPAND(HE_EXCEPT_CHOOSER(__VA_ARGS__, HE_EXCEPT_3, HE_EXCEPT_2)(__VA_ARGS__))
#endif

#endif