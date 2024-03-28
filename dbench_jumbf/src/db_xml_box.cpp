
#include "db_xml_box.h"

namespace dbench {

	DbXmlBox::DbXmlBox()
	{
		set_box_type("xml "); // there must be a space 
	}

	DbXmlBox::~DbXmlBox()
	{
	}

	DbXmlBox::DbXmlBox(char* xml, uint64_t xml_size)
	{
		set_box(xml, xml_size);
	}

	void DbXmlBox::set_box(char* xml, uint64_t xml_size)
	{
		set_box_type("xml ");
		set_box_payload((unsigned char*)xml, xml_size);
	}


}
