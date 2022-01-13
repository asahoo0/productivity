#include <core/pages.h>

const char *PagesList::GetTextForEnum(int enumVal) {
    return EnumStrings[enumVal];
}