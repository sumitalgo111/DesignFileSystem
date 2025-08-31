#pragma once
#include "FileSystemEntity.h"


class Folder : public FileSystemEntity
{
private:
	string name;
	FileSystemEntity* parentFolder; // pointer to the parent folder
	vector<FileSystemEntity*> contents; // contents of the folder

public:
	Folder(const string& name, FileSystemEntity* parent = NULL);
	~Folder();
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
};