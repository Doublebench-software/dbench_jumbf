#pragma once

#include "db_box.h"
#include "dbench_jumbf.h"

namespace dbench {

	class DbCborBox : public DbBox
	{
	public:
		DbCborBox();
		~DbCborBox();

		DbCborBox(char* cbor_data, uint64_t cbor_data_size);
		void set_box(char* cbor_data, uint64_t cbor_data_size);
	};



}