#include <iostream>

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}


int main (int argc, char *argv[])
{
    //declare Lua State
    lua_State* state1 = luaL_newstate();
    //init Lua state
    luaL_openlibs(state1);
    // read and execute script
    int ret = luaL_dofile(state1, "LuaTest.lua");
    //exit Lua State
    if(state1) lua_close(state1);

    return EXIT_SUCCESS;
}