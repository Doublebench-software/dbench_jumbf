#pragma once

#include "dbench_jumbf.h"
#include "db_box.h"

namespace dbench {

	class DbBinaryDataBox : public DbBox
	{
	public:
		DbBinaryDataBox();
		~DbBinaryDataBox();
		DbBinaryDataBox(unsigned char* binary_data, uint64_t binary_data_size);
		void set_box(unsigned char* binary_data, uint64_t binary_data_size);
	};

}