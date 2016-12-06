Sproto-cpp

Sproto(https://github.com/cloudwu/sproto) is a library like Google protobuffers,but it has only lua binding.This demo descibe how to use sproto in C++.

Remark:

Use spc.sh to generate pb file.
```
spc.sh addressnotemessage.sp addressnotemessage.pb
```


Usage
----------------------------
 - cmake & build	(Generate lua.exe\lpeg\bit32)
 - cd debug		
 - lua spc.lua  	(Generate sproto binary)
 - debug demo		(Need set workdir to debug)
 
 
sproto is not used, so do lsproto.c

 