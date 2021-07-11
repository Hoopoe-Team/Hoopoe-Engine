#include "Exception.h"

namespace Hoopoe 
{

Exception::Exception(const String& desc, const String& src) :
    Exception(desc, src, "", "", 0)
{}

Exception::Exception(const String& desc, const String& src, 
    const char* _type, const char* _file, long _line) :
        line(_line),
        typeName(_type),
        description(desc),
        source(src),
        file(_file)
{
    StringStream ss;

    ss << typeName << ": "
        << description
        << " in " << source;

    if( line > 0 )
    {
        ss << " at " << file << " (line " << line << ")";
    }

    fullDesc = ss.str();
}

Exception::Exception(const Exception& rhs) : 
    line(rhs.line), 
    typeName(rhs.typeName), 
    description(rhs.description), 
    source(rhs.source), 
    file(rhs.file)
{}

} // Hoopoe