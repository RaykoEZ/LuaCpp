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
    //luaL_dofile(state1, "LuaTest.lua");
    if (luaL_dofile(state1,"LuaTest.lua")) std::cout<<lua_tostring(state1,-1)<<'\n';
    //select function to call
    lua_getglobal(state1,"fact");
    //check if loaded valued is a function
    if(!lua_isfunction(state1,-1)) std::cout<<lua_tostring(state1,-1)<<'\n';

    //pushing args into function
    lua_pushnumber(state1,4);
    //lua_pushnumber(state1,4);
    //calling function from state1, 1 param, 1 result.
    if(lua_pcall(state1,1,1,0)!=0) std::cout<<lua_tostring(state1,-1)<<'\n';

    double ret = 0;
    //check if return type is number
    if(!lua_isnumber(state1,-1))
    {
        std::cout<<lua_tostring(state1,-1)<<'\n';
    }

    //std::cout<<"hey"<<'\n';
    ret = (double)lua_tonumber(state1,-1);
    //poping returned result off of lua stack
    lua_pop(state1,1);
    std::cout<<ret<<'\n';
    //exit Lua State
    if(state1) lua_close(state1);

    return EXIT_SUCCESS;
}