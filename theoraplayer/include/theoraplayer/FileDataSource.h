/// @file
/// @version 2.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Provides an interface for a video data source from a file.

#ifndef THEORAPLAYER_FILE_DATA_SOURCE_H
#define THEORAPLAYER_FILE_DATA_SOURCE_H

#include "DataSource.h"
#include "theoraplayerExport.h"

namespace theoraplayer
{	
	/**
		provides standard file IO
	*/
	class theoraplayerExport FileDataSource : public DataSource
	{
	public:
		FileDataSource(const std::string& filename);
		~FileDataSource();

		uint64_t getSize();
		uint64_t getPosition();
		std::string getFilename() { return this->filename; }

		std::string toString() { return this->filename; }

		int read(void* output, int nBytes);
		void seek(uint64_t byte_index);

	private:
		FILE* filePtr;
		std::string filename;
		uint64_t length;

		void openFile();

	};
}
#endif