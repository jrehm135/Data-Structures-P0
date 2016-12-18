#ifndef _PATH_H_
#define _PATH_H_

#include <string>

// TODO Comment
class Path {

public:
  const std::string root;
  const std::string separator;

  //This is the default constructor with no parameters
  Path();

  // This is the constructor with the parameters root and sep
  Path(std::string root, std::string sep);

  // This is the constructor with the parameters root, sep, and pathstring
  Path(std::string pathstring, std::string root, std::string sep);

  // This method checks to see if a string is nonempty and only includes standard ASCII characters
  bool isValid();

  // This method checks to see if a path is valid and begins with the proper root
  bool isAbsolute();

  // This method checks to see if a path is valid but does not begin with the proper root
  bool isRelative();

  // This method returns true if a path is a directory
  bool isDir();

  // This method returns the path
  std::string asString();

  // This returns the name of the file without its extension
  std::string basename();

  // This returns the extension of the file
  std::string extension();

  // This returns the directory of the path without its trailing separator
  std::string dirname();

  // This method will add a file to a directory and return true if possible.
  //  If the path is not a directory, it will return false
  bool appendFilename(std::string name);

  // This method will add a directory to a directory and returns true if possible.
  //  If the path is not a directory, it will return false
  bool appendDirname(std::string name);

private:
  // This string is used to store the full path
	std::string fullstring;
};

#endif // _PATH_H_
