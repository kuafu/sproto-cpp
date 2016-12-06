package.cpath = "./?.dll"
package.path = "./?.lua;lualib/?.lua;examples/?.lua;common/?.lua;"


--local spfile = arg[1]
file = io.open("./addressbook.sproto", "r")
print("-->", file)
scheme = file:read "*a"
file:close()
file = nil


local parser = require "sprotoparser"
local bin = parser.parse(scheme)

--local pbfile = arg[2]
file = io.open("addressbook.pb", "w")
file:write(bin)
file:close()

print("END")