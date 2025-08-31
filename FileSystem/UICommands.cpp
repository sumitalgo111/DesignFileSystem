#include "UICommands.h"

FileSystemEntity* UICommands::rootDirectory = nullptr;
FileSystemEntity* UICommands::currentDirectory = nullptr;

void UICommands::displayMenu()
{
	cout << "1. Create Folder" << endl;
	cout << "2. Create File" << endl;
	cout << "3. Open Folder/File" << endl;
	cout << "4. Rename Folder/File" << endl;
	cout << "5. Delete Folder/File" << endl;
	cout << "6. Display Info" << endl;
	cout << "7. Go Back" << endl;
	cout << "0. Exit" << endl;
}

void UICommands::handleUserInput(int choice)
{
	// Call method to create file
	string name, data;
	FileSystemEntity* entity = NULL;
	Folder* folder = NULL;

	//check if no directory exists
	if ((!rootDirectory || !currentDirectory) && choice != 1)
	{
		cout << "No Directory/Folder exists please create a folder first!" << endl;
		return;
	}

	// Handle user input and call appropriate methods
	switch (choice) {
	case 1:
		// Call method to create folder
		cout << "Creating Folder..." << endl;
		cout << "Enter folder name: ";
		cin >> name;

		entity = new Folder(name, currentDirectory);
		cout << "Folder named " << name << " created!" << endl;

		if (!rootDirectory)
			rootDirectory = entity;

		if (!currentDirectory)
		{
			cout << "Making this folder as current directory" << endl;
			currentDirectory = rootDirectory;
		}
		else
		{
			currentDirectory->addEntity(entity);
		}
		break;
	case 2:
		cout << "Creating File..." << endl;
		cout << "Enter file name: ";
		cin >> name;
		//cout << "Enter file content below....\n";
		//cin >> data;
		data = "data from file " + name;

		entity = new File(name, data, currentDirectory);
		currentDirectory->addEntity(entity);

		break;
	case 3:
		cout << "Opening Folder/File..." << endl;
		// Call method to open folder/file
		cout << "Enter Folder/File name: ";
		cin >> name;

		//find file in current directory
		entity = currentDirectory->findEntity(name);
		//if not found
		if (entity == NULL)
		{
			cout << "Folder/File Not Found in current directory!" << endl;
			return;
		}
		
		//if this is a type of folder
		folder = NULL;
		folder = dynamic_cast<Folder*>(entity);
		if (folder)
			currentDirectory = entity;
		else
			entity->open();

		break;
	case 4:
		// Call method to rename folder/file
		cout << "Enter current name: ";
		cin >> name;

		//find file in current directory
		entity = currentDirectory->findEntity(name);
		//if not found
		if (entity == NULL)
		{
			cout << "Folder/File Not Found!" << endl;
			return;
		}

		cout << "Renaming Folder/File..." << endl;
		cout << "Enter new name: ";
		cin >> name;
		entity->rename(name);
		cout << "Renamed Successfully!" << endl;
		break;
	case 5:
		// Call method to delete folder/file
		cout << "Enter the name: ";
		cin >> name;
		//find file in current directory
		entity = currentDirectory->findEntity(name);
		//if not found
		if (entity == NULL)
		{
			cout << "Folder/File Not Found in current directory!" << endl;
			return;
		}

		cout << "Deleting Folder/File..." << endl;
		if(currentDirectory->deleteEntity(entity))
			cout << "Deleted Successfully!" << endl;
		break;
	case 6:
		cout << "Displaying Info..." << endl;
		currentDirectory->displayInfo();
		break;
	case 7:
		if(currentDirectory && currentDirectory->getParent())
			currentDirectory = currentDirectory->getParent();
		else
			cout << "Already at root directory, cannot go back further!" << endl;
		break;
	default:
		cout << "Invalid Input..." << endl;
		break;
	}
}

void UICommands::run()
{
	int choice;

	while (true) {
		cout << endl;
		displayMenu();
		//print current path
		cout << endl << getPath() << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == EXIT_CODE)
			break;
		handleUserInput(choice);
	}

	if (rootDirectory)
	{
		rootDirectory->deleteEntity();
		delete rootDirectory;
		rootDirectory = NULL;
	}
}

string UICommands::getPath()
{
	if(!currentDirectory)
		return "";

	string path = currentDirectory->getName() + ": ";
	FileSystemEntity* temp = currentDirectory->getParent();
	while (temp)
	{
		path = temp->getName() + "/" + path;
		temp = temp->getParent();
	}
	return path;
}