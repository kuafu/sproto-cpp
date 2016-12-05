#pragma once
#include "common.h"

struct sproto;
class SMessage;

class DLLEXPORT CppSproto
{
public:
	CppSproto();
	~CppSproto();

	bool Init(const char* proto_bin, size_t pbsize);
	bool Encode(SMessage* msg, char* encbuf, int& size);
	bool Decode(SMessage* msg, const char* decbuf, int size);
	int Pack(const char* src, int src_size, char* dest, int dest_size);
	int Unpack(const char* src, int src_size, char* dest, int dest_size);

private:
	sproto* spro;
};

