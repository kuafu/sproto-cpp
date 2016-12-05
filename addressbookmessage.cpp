#include <iostream>
#include <string.h>
#include "addressbookmessage.h"

// PhoneNumberMessage
PhoneNumberMessage::PhoneNumberMessage()
	: type_(0)
{
}

PhoneNumberMessage::~PhoneNumberMessage()
{
}

string PhoneNumberMessage::GetMessageName()
{
	static const char* PhoneNumberMessageName = "PhoneNumber";
	return PhoneNumberMessageName;
}

bool PhoneNumberMessage::GetIntegerField(const char* name, int index, int64_t& value)
{
	if(strcmp(name, "type") == 0)
	{
		value = type_;
		return true;
	}
	else
	{
		return false;
	}
}

bool PhoneNumberMessage::SetIntegerField(const char* name, int index, int64_t value)
{
	if(strcmp(name, "type") == 0)
	{
		type_ = (int)value;
		return true;
	}
	else
	{
		return false;
	}
}

const char* PhoneNumberMessage::GetStringField(const char* name, int index, int& len)
{
	if(strcmp(name, "number") == 0)
	{
		if(number_.empty())
		{
			len = 0;
			return NULL;
		}
		else
		{
			len = number_.length();
			return &number_[0];
		}
	}
	else
	{
		return NULL;
	}
}

bool PhoneNumberMessage::SetStringField(const char* name, int index, const char* value, int len)
{
	if(strcmp(name, "number") == 0)
	{
		number_.assign(value, len);
		return true;
	}
	else
	{
		return false;
	}
}

void PhoneNumberMessage::Dump()
{
	cout << "\t\tnumber: " << number_ << endl;
	cout << "\t\ttype: ";
	switch(type_)
	{
	case 1:
		cout << "telephone" << endl;
		break;
	case 2:
		cout << "mobile phone" << endl;
		break;
	default:
		cout << "unknown" << endl;
		break;
	}
}

//////////////////////////////////////////////////////////////////////////
// PersonMessage
PersonMessage::PersonMessage()
	: id_(0)
{
}

PersonMessage::~PersonMessage()
{
	for(PhoneNumbersArray::iterator it = phonenumbers_.begin();
		it != phonenumbers_.end(); ++it)
	{
		PhoneNumberMessage* phonenumber = *it;
		delete phonenumber;
	}
}

string PersonMessage::GetMessageName()
{
	static const char* PersonMessageName = "Person";
	return PersonMessageName;
}

bool PersonMessage::GetIntegerField(const char* name, int index, int64_t& value)
{
	if(strcmp(name, "id") == 0)
	{
		value = id_;
		return true;
	}
	else
	{
		return false;
	}
}

bool PersonMessage::SetIntegerField(const char* name, int index, int64_t value)
{
	if(strcmp(name, "id") == 0)
	{
		id_ = (int)value;
		return true;
	}
	else
	{
		return false;
	}
}

const char* PersonMessage::GetStringField(const char* name, int index, int& len)
{
	if(strcmp(name, "name") == 0)
	{
		if(name_.empty())
		{
			len = 0;
			return NULL;
		}
		else
		{
			len = name_.length();
			return &name_[0];
		}
	}
	else if(strcmp(name, "email") == 0)
	{
		if(email_.empty())
		{
			len = 0;
			return NULL;
		}
		else
		{
			len = email_.length();
			return &email_[0];
		}
	}
	else
	{
		return NULL;
	}
}

bool PersonMessage::SetStringField(const char* name, int index, const char* value, int len)
{
	if(strcmp(name, "name") == 0)
	{
		name_.assign(value, len);
		return true;
	}
	else if(strcmp(name, "email") == 0)
	{
		email_.assign(value, len);
		return true;
	}
	else
	{
		return false;
	}
}

SMessage* PersonMessage::GetStructField(const char* name, int index)
{
	if(strcmp(name, "phones") == 0)
	{
		if(index >= 0 && index < (int)phonenumbers_.size())
			return phonenumbers_[index];
	}

	return NULL;
}

SMessage* PersonMessage::SetStructField(const char* name, int index)
{
	if(strcmp(name, "phones") == 0)
	{
		PhoneNumberMessage* msg = new PhoneNumberMessage;
		phonenumbers_.push_back(msg);
		return msg;
	}

	return NULL;
}

void PersonMessage::Dump()
{
	cout << "\tid: " << id_ << endl;
	cout << "\tname: " << name_ << endl;
	cout << "\temail: " << email_ << endl;

	for(PhoneNumbersArray::iterator it = phonenumbers_.begin();
		it != phonenumbers_.end(); ++it)
	{
		PhoneNumberMessage* phonenumber = *it;
		phonenumber->Dump();
	}
}


//////////////////////////////////////////////////////////////////////////
// AddressBookMessage
AddressBook::AddressBook()
{
}

AddressBook::~AddressBook()
{
	for(PersonVector::iterator it = persons_.begin(); it != persons_.end(); ++it)
	{
		PersonMessage* person = *it;
		delete person;
	}
}

string AddressBook::GetMessageName()
{
	static const char* AddressBookMessageName = "AddressBook";
	return AddressBookMessageName;
}

SMessage* AddressBook::GetStructField(const char* name, int index)
{
	if(strcmp(name, "persons") == 0)
	{
		if(index >= 0 && index < (int)persons_.size())
			return persons_[index];
	}

	return NULL;
}

SMessage* AddressBook::SetStructField(const char* name, int index)
{
	if(strcmp(name, "persons") == 0)
	{
		PersonMessage* msg = new PersonMessage;
		persons_.push_back(msg);
		return msg;
	}

	return NULL;
}

void AddressBook::Dump()
{
	cout << "{" << endl;
	for(PersonVector::iterator it = persons_.begin(); it != persons_.end(); ++it)
	{
		PersonMessage* person = *it;
		person->Dump();
	}
	cout << "}" << endl;
}

