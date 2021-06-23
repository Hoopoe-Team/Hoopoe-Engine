#include "../include/Exception.h"

namespace Hoopoe 
{

Exception::Exception(int num, const String& desc, const String& src) :
    Exception(num, desc, src, "", "", 0)
{}

Exception::Exception(int num, const String& desc, const String& src, 
    const char* typ, const char* fil, long lin) :
        line(lin),
        typeName(typ),
        description( desc ),
        source(src),
        file(fil)
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

Exception::Exception(const Exception& rhs)
    : line( rhs.line ), 
    typeName( rhs.typeName ), 
    description( rhs.description ), 
    source( rhs.source ), 
    file( rhs.file )
{}

}