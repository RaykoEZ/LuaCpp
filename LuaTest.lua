--print("hello world.")

-- defines a factorial function
function fact (n) 
    -- check for decimal input which doesn't work with normal factorial
    if math.ceil(n) > math.floor(n) then return "Too lazy to implement Gamma Function."
    -- string return for errors
    elseif n < 0 then return "Cannot calculate factorial : (-ve)!"
    elseif n == 0 then
        return 1
    else
        return n * fact(n-1) -- recursion boys!
    end
    return "invalid input"
end

function f (x, y)
    return (x^2 * math.sin(y))/(1 - x)
end
--print("enter a number:")
--a = io.read("*number")        -- read a number
--print(fact(a))