#pragma once
#include "FileSystemEntity.h"

class File : public FileSystemEntity
{
private:
	string name;
	string data; // file content
	FileSystemEntity* parentFolder; // pointer to the parent folder
public:
	File(const string& name, const string& data, FileSystemEntity* parent = NULL);
	void displayInfo() const;
	void open() const;
	size_t getSize() const;
	string getName() const;
	string getType() const;
	FileSystemEntity* getParent() const;
	void rename(const string& newName);
	bool deleteEntity(FileSystemEntity* entity = NULL);
	bool addEntity(FileSystemEntity* entity);
	FileSystemEntity* findEntity(const string& name);
	~File();
};