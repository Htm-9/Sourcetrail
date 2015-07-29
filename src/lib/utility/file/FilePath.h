#ifndef FILE_PATH_H
#define FILE_PATH_H

#include <string>

#include "boost/filesystem.hpp"

class FilePath
{
public:
	FilePath();
	FilePath(const char* filePath);
	FilePath(const std::string& filePath);
	FilePath(const boost::filesystem::path& filePath);

	boost::filesystem::path path() const;

	bool empty() const;
	bool exists() const;
	bool isDirectory() const;
	bool isAbsolute() const;

	FilePath parentDirectory() const;

	FilePath absolute() const;
	FilePath canonical() const;
	FilePath relativeTo(const FilePath& other) const;
	FilePath concat(const FilePath& other) const;

	std::string str() const;
	std::string fileName() const;

	std::string extension() const;
	FilePath withoutExtension() const;
	bool hasExtension(const std::vector<std::string>& extensions) const;

	bool operator==(const FilePath& other) const;
	bool operator!=(const FilePath& other) const;
	bool operator<(const FilePath& other) const;

private:
	void init();

	boost::filesystem::path m_path;
	bool m_exists;
};

#endif // FILE_PATH_H
