#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FileSystemEntity
{
public:
	virtual ~FileSystemEntity() = default;
	virtual void displayInfo() const = 0;
	virtual void open() const = 0;
	virtual size_t getSize() const = 0;
	virtual string getName() const = 0;
	virtual string getType() const = 0;
	virtual FileSystemEntity* getParent() const = 0;
	virtual void rename(const string& newName) = 0;
	virtual bool deleteEntity(FileSystemEntity* entity = NULL) = 0;
	virtual bool addEntity(FileSystemEntity* entity) = 0;
	virtual FileSystemEntity* findEntity(const string& name) = 0;
};
// End of FileSystemEntity.h