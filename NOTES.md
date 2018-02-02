## Github link to this demo

https://github.com/RaykoEZ/LuaCpp

## Addtional notes after implementing the demo:

- Lua tables and metatables

```lua
--table example in documentation
--https://www.lua.org/pil/2.5.html

a = {}     -- create a table and store its reference in `a'
    k = "x"
    a[k] = 10        -- new entry, with key="x" and value=10
    a[20] = "great"  -- new entry, with key=20 and value="great"
    print(a["x"])    --> 10
    k = 20
    print(a[k])      --> "great"
    a["x"] = a["x"] + 1     -- increments entry "x"
    print(a["x"])    --> 11



--meta tables and meta methods
--https://www.lua.org/pil/13.html
t = {}
t1 = {}
setmetatable(t, t1)
assert(getmetatable(t) == t1)

-- meta method, it acts like a specialized struct - a class if needed
Set = {}
    
    function Set.new (t)
      local set = {}
      for _, l in ipairs(t) do set[l] = true end
      return set
    end
    
    function Set.union (a,b)
      local res = Set.new{}
      for k in pairs(a) do res[k] = true end
      for k in pairs(b) do res[k] = true end
      return res
    end
    
    function Set.intersection (a,b)
      local res = Set.new{}
      for k in pairs(a) do
        res[k] = b[k]
      end
      return res
    end



```

