#pragma once

#include "db_box.h"
#include "dbench_jumbf.h"

namespace dbench {

	class DbJsonBox : public DbBox
	{
	public:
		DbJsonBox();
		~DbJsonBox();

		DbJsonBox(char* json_data, uint64_t json_data_size);
		void set_box(char* json_data, uint64_t json_data_size);
	};



}