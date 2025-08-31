#include "Folder.h"

//Folder class implementation
Folder::Folder(const string& name, FileSystemEntity* parent) : name(name), parentFolder(parent) {
	// Implementation for Folder constructor
}

void Folder::displayInfo() const
{
	// Implementation for displaying folder info
	cout << "Folder: " << getName() << ", Items: " << contents.size() << ", Size: " << getSize() << " bytes" << endl;

	if(contents.size() == 0)
		return;

	cout << "Items..... " << endl;

	for (const auto& item : contents) {
		if(item->getType() == "FOLDER")
			cout << "Folder: " << item->getName() << ", Items: " << dynamic_cast<Folder*>(item)->contents.size() << ", Size: " << item->getSize() << " bytes" << endl;
		else
			item->displayInfo();
	}
}

void Folder::open() const
{
	cout << "Current Folder Name: " << name << endl;
	// Implementation for opening a folder
	for (const auto& item : contents) {
		cout << (item->getName()) << endl;
	}
}
size_t Folder::getSize() const
{
	// Implementation for getting folder size
	size_t totalSize = 0;
	for (const auto& item : contents) {
		totalSize += item->getSize();
	}

	return totalSize;
}
string Folder::getName() const
{
	// Implementation for getting folder name
	return name;
}
string Folder::getType() const
{
	// Implementation for getting folder name
	return "FOLDER";
}

FileSystemEntity* Folder::getParent() const
{
	// Implementation for getting parent folder
	return parentFolder;
}

void Folder::rename(const string& newName)
{
	// Implementation for renaming a folder
	name = newName;
}

bool Folder::deleteEntity(FileSystemEntity* entity)
{
	// Implementation for deleting a folder
	// Ensure the folder is empty before deletion

	if (entity == NULL)
	{
		bool isDeleted = true;
		for (auto item : contents)
		{
			if (!item->deleteEntity())
			{
				isDeleted = false;
				break;
			}
			//delete instance of item
			delete item;
			//mark as NULL
			item = NULL;
		}

		//swap to restore original contents if deletion failed
		vector<FileSystemEntity*> tempContents = contents;
		for (auto& item : contents) {
			if (item != nullptr)
				tempContents.push_back(item);
		}

		tempContents.swap(contents);
		tempContents.clear();
		return isDeleted;
	}
	else
	{
		if (!entity->deleteEntity())
		{
			cout << "Folder deletion aborted." << endl;
			return false;
		}
		delete entity;
		cout << "Folder deletion success." << endl;
		//remove entity from contents
		contents.erase(remove(contents.begin(), contents.end(), entity), contents.end());
		return true;
	}
}

bool Folder::addEntity(FileSystemEntity* entity)
{
	contents.push_back(entity);
	return true;
}

FileSystemEntity* Folder::findEntity(const string& name)
{
	//do nothing
	for (auto entity : contents)
	{
		if (entity->getName() == name)
			return entity;
	}
	return NULL;
}

Folder::~Folder()
{
	contents.clear();
	cout << "Folder named " << name << " destroyed!" << endl;

}