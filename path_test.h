#include <cxxtest/TestSuite.h>

#include "path.h"

class PathTests : public CxxTest::TestSuite {
public:
  //This method simply checks if one of the constructors is working properly
	void test_example(void) {
	//Path p();
	Path p("C:\\", "\\");
	//Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");

    TS_ASSERT_EQUALS(p.root, "C:\\");
    TS_ASSERT_EQUALS(p.separator, "\\");
	
  }
	//This checks if isValid() works with standard ASCII text
  void testIsValid(void) {
	  Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");
	  bool valid = p.isValid();

	  TS_ASSERT_EQUALS(valid, true)

  }
  //This checks if isValid() works with extended ASCII text
  void testIsValid1(void) {
	  Path p("C:\\home\\ê", "C:\\", "\\");
	  bool valid = p.isValid();

	  TS_ASSERT_EQUALS(valid, false)

  }
	//This checks to see if this pathname is absolute or not
  void testIsAbsolute(void) {
	  Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");
	  bool valid = p.isAbsolute();

	  TS_ASSERT_EQUALS(valid, true)

  }
  //This checks to see if this pathname is relative or not
  void testIsRelative(void) {
	  Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");
	  bool valid = p.isRelative();

	  TS_ASSERT_EQUALS(valid, false)

  }
  //This checks to see if a path is a directory
  void testIsDir(void) {
	  Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");
	  bool valid = p.isDir();

	  TS_ASSERT_EQUALS(valid, false)

  }
  //This returns the path as a string
  void testAsString(void) {
	  Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");
	  std::string valid = p.asString();

	  TS_ASSERT_EQUALS(valid, "C:\\home\\users\\dumbo\\file.txt")

  }
  //This returns the filename of a file with no extension
  void testBaseName(void) {
	  Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");
	  std::string valid = p.basename();

	  TS_ASSERT_EQUALS(valid, "file")

  }
  //This returns the extension of a file with no filename
  void testExtension(void) {
	  Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");
	  std::string valid = p.extension();

	  TS_ASSERT_EQUALS(valid, "txt")

  }
  //This checks the directory of a path
  void testDirName(void) {
	  Path p("C:\\home\\users\\dumbo\\file.txt", "C:\\", "\\");
	  std::string valid = p.dirname();

	  TS_ASSERT_EQUALS(valid, "C:\\home\\users\\dumbo")

  }
  //This appends a file to the end of a path and returns true if successful
  void testAppendFilename(void) {
	  Path p("C:\\home\\users\\dumbo\\", "C:\\", "\\");
	  bool valid = p.appendFilename("file.txt");

	  TS_ASSERT_EQUALS(valid, true)

  }
  //This apends a directory to the end of a path and returns true if successful
  void testAppendDirname(void) {
	  Path p("C:\\home\\users\\dumbo\\", "C:\\", "\\");
	  bool valid = p.appendDirname("file");

	  TS_ASSERT_EQUALS(valid, true)

  }
};
