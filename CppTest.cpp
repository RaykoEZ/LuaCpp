#include <iostream>

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

//doing something
int luaFactorial( lua_state* _state, int _num)
{   
    int ret;

    lua_getglobal(_state, "fact");

    return ret;
}

void initLua()
{

}

int main (int argc, char *argv[])
{
    //declare Lua State
    lua_State* state1 = luaL_newstate();
    //init Lua state
    state1 = lua_open();

    //exit Lua State
    if(state1) lua_close(state1);

    return EXIT_SUCCESS;
}
