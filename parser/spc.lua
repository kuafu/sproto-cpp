package.cpath = "./?.so"
package.path = "./?.lua;lualib/?.lua;examples/?.lua;common/?.lua;"

local parser = require "sprotoparser"

--local spfile = arg[1]
file = io.open("./addressbook.sproto", "r")
print("-->", file)
scheme = file:read "*a"
file:close()
file = nil


local bin = parser.parse(scheme)

--local pbfile = arg[2]
file = io.open("addressbook.pb", "ab")
file:write(bin)
file:close()

