#include <iostream>

using namespace std;
using namespace System;
using namespace System::IO;
namespace ConsoleApplication2
{
	public ref class Program
	{
	public:
		static void Main()
		{
			// Loop through all the immediate subdirectories of C.
			for each (String ^ entry in Directory::GetDirectories("G:\\учёба\\"))
			{
				DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry));
				for each (String ^ inEntry in Directory::GetDirectories(entry))
				{
					DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(inEntry));
				}
				for each (String ^ inEntry in Directory::GetFiles(entry))
				{
					DisplayFileSystemInfoAttributes(gcnew FileInfo(inEntry));
				}
			}
			// Loop through all the files in C.
			for each (String ^ entry in Directory::GetFiles("G:\\учёба\\"))
			{
				DisplayFileSystemInfoAttributes(gcnew FileInfo(entry));
			}
		}
		static void DisplayFileSystemInfoAttributes(FileSystemInfo^ fsi)
		{
			// Assume that this entry is a file.
			String^ entryType = "File";
			// Determine if entry is really a directory
			if ((fsi->Attributes & FileAttributes::Directory) == FileAttributes::Directory)
			{
				entryType = "Directory";
			}
			// Show this entry's type, name, and creation date.
			Console::WriteLine("{0} entry {1} was created on {2:D}", entryType, fsi->FullName, fsi->CreationTime);
			if ((fsi->Attributes & FileAttributes::Directory) != FileAttributes::Directory)
			{
				Console::WriteLine("File Attributes: {0}", fsi->FileSystemInfo::Attributes);
			}
		}
	};
};
int main()
{
	ConsoleApplication2::Program::Main();
	Console::ReadKey();
}