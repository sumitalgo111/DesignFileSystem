#include "File.h"

File::File(const string& name, const string& data, FileSystemEntity* parent) : name(name), data(data), parentFolder(parent) {
	// Implementation for File constructor
}

void File::displayInfo() const
{
	// Implementation for displaying file info
	cout << "File: " << getName() << ", Size: " << getSize() << " bytes" << endl;
}

void File::open() const
{
	// Implementation for opening a file
	cout << "Opening File Name: " << name << endl;
	cout << "Contents of the file ..." << name << endl;
	cout << data << endl;
	cout << "End of file content..." << endl;
}
size_t File::getSize() const
{
	// Implementation for getting file size
	return data.size()*sizeof(char);
}
string File::getName() const
{
	// Implementation for getting file name
	return name;
}
string File::getType() const
{
	// Implementation for getting folder name
	return "FILE";
}
FileSystemEntity* File::getParent() const
{
	// Implementation for getting parent folder
	return parentFolder;
}
void File::rename(const string& newName)
{
	// Implementation for renaming a file
	name = newName;
}

bool File::deleteEntity(FileSystemEntity* entity)
{
	// Implementation for deleting a file
	if (name == "protected.txt") {
		cout << "Error: Cannot delete protected file." << endl;
		return false; // Return false if deletion fails
	}

	return true; // Return true if deletion is successful
}

bool File::addEntity(FileSystemEntity* entity)
{
	//do nothing
	return false;
}

FileSystemEntity* File::findEntity(const string& name)
{
	//do nothing
	return NULL;
}

File::~File()
{
	cout << "File named " << name << " destroyed!" << endl;
}