#define CATCH_CONFIG_MAIN 
#include "catch/catch.hpp"

#include <iostream>
#include <sys/stat.h>
#include "tangram.h"

TEST_CASE( "Compare byte size of allocated resource to os file size", "[Core][bytesFromResource]" ) {
    unsigned int size;
    unsigned char* data = bytesFromResource("polygon.fs", &size); 
    
    // ask os for size
    struct stat st;
    stat("core/resources/polygon.fs", &st);
    unsigned int sys_size = st.st_size;

    REQUIRE(sys_size == size);
    
    free(data);
}
