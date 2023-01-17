#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "../yaml/Yaml.hpp"

char tmpBuffer[8196];

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    memcpy(tmpBuffer, Data, Size);

    Yaml::Node root;
    try {
        Yaml::Parse(root, tmpBuffer, Size);
    } catch (const Yaml::ParsingException) {
    } catch (const Yaml::InternalException) {

    }
    
    return 0;
}