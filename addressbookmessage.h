#pragma once

#include <string>
#include <vector>
#include "SMessage.h"
using namespace std;

class PhoneNumberMessage : public SMessage
{
public:
	PhoneNumberMessage();
	virtual ~PhoneNumberMessage();

	virtual string GetMessageName();
	virtual bool GetIntegerField(const char* name, int index, int64_t& value);
	virtual bool SetIntegerField(const char* name, int index, int64_t value);
	virtual const char* GetStringField(const char* name, int index, int& len);
	virtual bool SetStringField(const char* name, int index, const char* value, int len);

	void SetNumber(const string& number) { number_ = number; }
	void SetType(int type) { type_ = type; }
	void Dump();

private:
	string number_;
	int type_;
};

class PersonMessage : public SMessage
{
public:
	PersonMessage();
	virtual ~PersonMessage();

	virtual string GetMessageName();
	virtual bool GetIntegerField(const char* name, int index, int64_t& value);
	virtual bool SetIntegerField(const char* name, int index, int64_t value);
	virtual const char* GetStringField(const char* name, int index, int& len);
	virtual bool SetStringField(const char* name, int index, 
			const char* value, int len);
	virtual SMessage* GetStructField(const char* name, int index);
	virtual SMessage* SetStructField(const char* name, int index);

	void SetName(const string& name) { name_ = name; }
	void SetId(int id) { id_ = id; }
	void SetEmail(const string& email) { email_ = email; }
	void AddPhoneNumber(PhoneNumberMessage* phonenumber) { 
		phonenumbers_.push_back(phonenumber); 
	}
	void Dump();

private:
	string name_;
	int id_;
	string email_;
	typedef vector<PhoneNumberMessage*> PhoneNumbersArray;
	PhoneNumbersArray phonenumbers_;
};

class AddressBook : public SMessage
{
public:
	AddressBook();
	virtual ~AddressBook();

	virtual string GetMessageName();
	virtual SMessage* GetStructField(const char* name, int index);
	virtual SMessage* SetStructField(const char* name, int index);

	void AddPerson(PersonMessage* person) { persons_.push_back(person); }
	void Dump();

private:
	typedef vector<PersonMessage*> PersonVector;
	PersonVector persons_;
};

