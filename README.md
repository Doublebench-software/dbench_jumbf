# Doublebench JUMBF (Dbench-JUMBF).

## Introduction
The Dbench-JUMBF aims to provide the means to support the generation and manipulation of JUMBF data. The dbench-jumbf library, covers the respective JPEG Universal Metadata Format (JUMBF) standard (ISO/IEC 19566-5) including the amendments and revised editions that have been issued.

The dbench-jumbf is the main library that all other libraries or applications should rely on. The dbench-jumbf library provides the means to generate and parse information that is stored in JUMBF format. The library is implemented in C++ with an object-oriented approach, and it uses ISO C++14 Standard.
As specified in ISO/IEC 19566-5, it is possible to store JUMBF data as standalone files or inside a host image by embedding the boxes in APP11 markers. Regarding the first case, the jumbf library provides the classes to parse and generate JUMBF data directly from standalone files. Regarding the generation of standalone JUMBF data, the file extension ".jumbf" is used, corresponding to the concatenation of ISO Base Media File Format boxes. The current version of the library supports JPEG 1 files and standalone jumbf files. 

This repository also include the "dbench-jumbf-app" which is a command line application (cmd) on the top of dbench-jumbf library. The application can be used to generate and parse the jumbf standalone files or jumbf in JPEG 1 files.

## Build the software
To build the software, CMake Scripts are included. Using the following commands the software can be build. The CMake should be installed on the machine. 
### Windows:
1.	Open command prompt in folder where the source code is present.
2.	Run the following commands.
	a.	`mkdir build`
	b.	`cd build`
	c.	`cmake .\..`
	d.	`cmake --build .`
3.	The software is built and ready to use. Note that CMake GUI can also be used for building on Windows machines.
### Linux:
1.	In terminal go to the directory where the source code lies. 
2.	Run the following commands.
	a.	`mkdir build`
	b.	`cd build`
	c.	`cmake ../`
	d.	`make` 
4.	The software is built and ready to use. 

## Usage.
The command line parameters can be used for the "dbench-jumbf-app" to generate or parse JUMBF files. 
### Example commands
**Example 1** 
<br> `dbench_jumbf_app -encode -xml_file XML_FILE.xml` <br>
This command will generate XML JUMBF Box and will write the JUMBF bitstream to db_output.jumbf file. 

**Example 2** 
<br> `dbench_jumbf_app -encode -json_file JSON_FILE.json -label "Example of JSON Content Box" -o example_json.jumbf`
<br> This command will generate a JSON JUMBF Box and will write the JUMBF bitstream to example_json.jumbf file. 

**Example 3**
<br>`dbench_jumbf_app -encode -host_file image.jpg -xml_file content.xml -label "This is a sample xml content JUMBF box"" -o image_with_jumbf.jpg`
<br>This command will generate XML JUMBF Box with the provided label and will embed the JUMBF bitstream to “image_with_jumbf.jpg” file.  Figure 4 shows the configuration. 

**Example 4** 
<br>`dbench_jumbf_app -parse -i db_output.jumbf.`
<br>This command will parse the "db_output.jumbf" file and will print the values to the screen. 

### Parameters
| No    | Parameter      | Possible value	| Description										|
| ----- | -------------- | ---------------- | ------------------------------------------------	|
| 1	 	| -encode		 |					| Encode or Generate JUMBF (default)				|
| 2	 	| -parse		 |					| Parse a .jumbf or .jpg file						|
| 3	 	| -host_file	| INPUT FILENAME		| For encoding (-encode), Specify input JPEG 1 file name that will host the JUMBF. It should have .jpg or .jpeg file extension. |
| 4	 	| -i			| INPUT FILE NAME	| Specify input file name with .jpg or .jumbf extension for parsing. |
| 5	 	| -o			| OUTPUT FILENAME	| Specify output file name. If -host_file is provided then the output should be .jpg or .jpeg else the output should be .jumbf. <br>If this parameter is not provided then the default file name "db_output.jumbf" will be used. |
| 6	 	| -content_type	| XML, JSON, JP2C, UUID, CBOR, EMBEDDED_FILE. |	Specify JUMBF content type. If not provided then it will be determined from content data file extension.  |
| 7	 	| -lbox			|  0, 1 or NULL	| Specify Lbox field.<br> 0 = box size will be file size i.e Box will continue till EOF. <br> 1 = box size will be present in XLbox field <br> NULL = box size will be present in Lbox or XLbox field. <br> If this parameter is not provided then the "NULL" will be used by default. |
| 8	 	| -requestable	|					| Set requestable field to true in JUMBF Description box. |
| 9	 	| -label		| LABEL STRING		| Specify Label for JUMB Description box. |
| 10 	| -id			| +ive Integer		| Specify ID for JUMB Description box. <br>The number should be less than 2<sup>32</sup>-1.|
| 11 	| -hash			| HASH				| Specify hash/signature for JUMB Description box. HASH should be string of 64 characters. each 2 characters represent a HEX byte. |
| 12 	| -hash_file	| HASH FILE NAME		| Specify file name for hash/signature to put in JUMB Description box. HASH_FILE should contain only string of 64 characters in binary. each 2 characters represent a HEX byte |
| 13 	| -private_data_file | FILE NAME	| Specify file name for private box data to put in JUMB Description box. FILE NAME should contain binary bitstream in accordance with Box definition|
| 14	| -xml_file		| XML FILE NAME		| Specify file name (.xml) for xml data to put in JUMBF Content box.<br> If -xml_file is provided then "-content_type" become optional as the software will assign "XML" to JUMBF Content box type (-content_type). |
| 15	| -codestream_file | FILE NAME	| Specify file name for codestream data to put in JUMBF Content box.<br> If -codestream_file is provided then "-content_type" become optional as the software will assign "CODESTREAM" to JUMBF Content box type (-content_type). |
| 16	| -json_file		| JSON FILE NAME | Specify file name (.json) for json data to put in JUMBF Content box. <br> If -json_file is provided then "-content_type" become optional as the software will assign "JSON" to JUMBF Content box type (-content_type). |
| 17	| -uuid			| UUID				| Specify UUID for UUID field to put in JUMBF Content box. <br> UUID should be string of characters. each 2 characters represent a HEX byte character \"-\" will ignored by the software. <br> Examples: 663295b0-2158-42de-b16f-a4e458237885 and 663295b0215842deb16fa4e458237885 |
| 18	| -uuid_data_file | FILE NAME		| Specify file name for UUID box paylaod data to put in JUMBF Content box. |
| 19	| -embed_file	| FILE NAME			| Specify name of the file, the content of which will be embed in JUMBF Content box. |
| 20	| -media_type	| MEDIA_TYPE			| Specify media type to put in File Description box. |
| 21	| -include_filename |					| Specify flag for file name to put in File Description box. |
| 22	| -reference_external |				| Specify flag reference as external flag in File Description box.<br> If this flag is provided then "-embed_file" wil be used as external link and the flag will on.|
| 23	| -cbor_file		| FILE NAME			| Specify file name (.cbor) for CBOR data to put in JUMBF Content box. |
| 24	| -free_bytes	| +ive Intger		| Specify number of padding bytes for JUMBF padding box.<br> If this is provided then padding box with tbox = FREE wil be generated and included in JUMBF.<br>The number should be less than 2<sup>32</sup>-1.|
| 25	| -csv_file		| DATASET FILE NAME	| Specify the ".csv" file name. <br> For encoding (-encode), the ".csv" file shoul have the data in accordance with JPEG JUMBF Dataset <br> For parsing (-parse), the values by parsing different fields will be written to ".csv" file. The values will be in accordance with the JPEG JUMBF reference report.   |
| 26	| -row_number	| +ive integer		| Specify row number in dataset file name. If this is provided then specified row number data will be used and single output file will genereated otherwise all the rows will be considered and number of output files will be same as the number of rows in the dataset file. |
| 27	| -input_dir	| INPUT FOLDER PATH	| Specify input directory name. <br> In encoding process (-encode), this folder should exist and shall contains all in input files. <br> In parsing process (-parse), this folder should exists and shall contain all the .jumbf or .jpg files. |
| 28	| -output_dir	| OUTPUT FOLDER PATH	| Specify directory name for output files. |
| 29	| -h or -help	|					| Print description of command line argments. |
| 30	| -v or -version |					| Print version of the application. |

## License
 See the ([License]) file.

## Contact
If you encounter a bug or other issue with the software, please reach to YNM Systems Inc. (sales@doublebench.com) or visit www.doublebench.com.