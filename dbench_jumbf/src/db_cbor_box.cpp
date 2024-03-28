
#include "db_cbor_box.h"

namespace dbench {

	DbCborBox::DbCborBox()
	{
		set_box_type("cbor");
	}

	DbCborBox::~DbCborBox()
	{
	}

	DbCborBox::DbCborBox(char* cbor, uint64_t cbor_size)
	{
		set_box(cbor, cbor_size);
	}

	void DbCborBox::set_box(char* cbor, uint64_t cbor_size)
	{
		set_box_type("cbor");
		set_box_payload((unsigned char*)cbor, cbor_size);
	}

}
