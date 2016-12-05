#include "SMessage.h"

bool SMessage::GetIntegerField(const char* name, int index, int64_t& value)
{
	return false;
}

bool SMessage::SetIntegerField(const char* name, int index, int64_t value)
{
	return false;
}

bool SMessage::GetBooleanField(const char* name, int index, bool& value)
{
	return false;
}

bool SMessage::SetBooleanField(const char* name, int index, bool value)
{
	return false;
}

const char* SMessage::GetStringField(const char* name, int index, int& len)
{
	return NULL;
}

bool SMessage::SetStringField(const char* name, int index, const char* value, int len)
{
	return false;
}

SMessage* SMessage::GetStructField(const char* name, int index)
{
	return NULL;
}

SMessage* SMessage::SetStructField(const char* name, int index)
{
	return NULL;
}

