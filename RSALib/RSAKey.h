#pragma once
#include <Windows.h>

class RSAKey
{
public:
	RSAKey() {}
	virtual ~RSAKey() = 0 {}

	virtual bool setKey( const char* buff, DWORD buffSize ) = 0;

	bool base64Encode( const BYTE* buff, DWORD buffSize, char*& encodedBuff, DWORD& encodedBuffSize );
	bool base64Decode( const char* buff, DWORD buffSize, BYTE*& decodedBuff, DWORD& decodedBuffSize );

protected:
#pragma pack(push, 1)
	union b64Type
	{
		DWORD triplet : 24;
		struct
		{
			char c1, c2, c3;
		};
		struct
		{
			DWORD t1 : 6;
			DWORD t2 : 6;
			DWORD t3 : 6;
			DWORD t4 : 6;
		};
	};

	struct DER_TLV
	{
		union
		{
			BYTE tag;
			struct
			{
				BYTE tagNum : 5;
				BYTE form : 1;
				BYTE asn1Class : 2;
			};
		} tag;
		DWORD length;
		BYTE* value;
	};

	union BigEndianDWORD
	{
		DWORD num;
		char c1, c2, c3, c4;
		char arr[4];
	};
#pragma pack(pop)

	bool eliminateHeader( const char*& buff, DWORD& buffSize );
	bool readDER_TLV( BYTE*& dataPtr, DER_TLV& der );
	void setDER_Values( DER_TLV& der, BYTE*& param, DWORD& paramSize );

//private:
	static const char base64chars[];
	static const char base64charsDecode[];

	const BYTE SEQUENCE = 0x30;
	const BYTE INTEGER =  0x02;

};
