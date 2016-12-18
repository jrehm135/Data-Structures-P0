#include "path.h"

// TODO implement Path
Path::Path():root("/"), separator("/")
{
	fullstring = "/";
}
Path::Path(std::string root, std::string sep):root(root), separator(sep)
{
	fullstring = root;
}
Path::Path(std::string pathstring, std::string root, std::string sep):root(root), separator(sep)
{
	fullstring = pathstring;
}
bool Path::isValid()
{
	int len = fullstring.size();
	bool isvalid = true;
	if (len == 0)
		isvalid = false;
	else {
		for (int i = 0; i < len; i++) {
			if (fullstring[i] < 32 || fullstring[i] > 127) {
				isvalid = false;
			}

		}
	}
	return isvalid;
}
bool Path::isAbsolute()
{
	bool check = isValid();
	int rootlen = root.length();
	std::string newroot = fullstring.substr(0, rootlen);
	if (newroot == root && check == true)
		return true;
	else return false;
}
bool Path::isRelative()
{
	bool check = isValid();
	int rootlen = root.length();
	std::string newroot = fullstring.substr(0, rootlen);
	if (newroot != root && check == true)
		return true;
	else return false;
}
bool Path::isDir() 
{
	int len = fullstring.length();
	int slash = fullstring.find_last_of(separator);
	if (slash == len-1)
		return true;
	else return false;
}
std::string Path::asString()
{
	return fullstring;
}
std::string Path::basename()
{
	int pos1 = fullstring.find_last_of(separator);
	int pos2 = fullstring.find_last_of(".");
	int diff = pos2 - pos1;
	if (pos1 != -1 && pos2 != -1)
	{
		std::string filename = fullstring.substr(pos1 + 1, diff - 1);
		return filename;
	}
	else return "";
}
std::string Path::extension()
{
	int pos1 = fullstring.find_last_of(separator);
	int pos2 = fullstring.find_last_of(".");
	if (pos1 != -1 && pos2 != -1)
	{
		std::string extension = fullstring.substr(pos2 + 1);
		return extension;
	}
	else return "";
}
std::string Path::dirname() 
{
	int pos1 = fullstring.find_last_of(separator);
	if (pos1 != -1)
	{
		std::string dir = fullstring.substr(0, pos1);
		return dir;
	}
	else return "";
}
bool Path::appendFilename(std::string name)
{
	if (isDir())
	{
		fullstring = fullstring + name;
		return true;
	}
	else return false;

}
bool Path::appendDirname(std::string name)
{
	if (isDir())
	{
		fullstring = fullstring + name + separator;
		return true;
	}
	else return false;
}