#include "StringUtil.h"

namespace Hoopoe
{

void StringUtil::trim(String& str, bool left, bool right)
{
    static const String delims = " \t\r\n";
    if(right)
        str.erase(str.find_last_not_of(delims)+1); // trim right
    if(left)
        str.erase(0, str.find_first_not_of(delims)); // trim left
}

} // Hoopoe