#include "RSAPrivateKey.h"


RSAPrivateKey::RSAPrivateKey()
{
	version = 0;
	modulus = publicExponent = privateExponent = prime1 = prime2 = exponent1 = exponent2 = coefficient = otherPrimeInfos = NULL;
}


RSAPrivateKey::~RSAPrivateKey()
{
	if( modulus != NULL )
		delete[] modulus;
	modulusSize = 0;

	if( modulus != NULL )
		delete[] publicExponent;
	publicExponentSize = 0;

	if( privateExponent != NULL )
		delete[] privateExponent;
	privateExponentSize = 0;

	if( prime1 != NULL )
		delete[] prime1;
	prime1Size = 0;

	if( prime2 != NULL )
		delete[] prime2;
	prime2Size = 0;

	if( exponent1 != NULL )
		delete[] exponent1;
	exponent1Size = 0;

	if( exponent2 != NULL )
		delete[] exponent2;
	exponent2Size = 0;

	if( coefficient != NULL )
		delete[] coefficient;
	coefficientSize = 0;

	if( otherPrimeInfos != NULL )
		delete[] otherPrimeInfos;
	otherPrimeInfos = 0;
}

/****** BEGIN RSA PRIVATE KEY Format***********
RSAPrivateKey ::= SEQUENCE {
  version           Version,
  modulus           INTEGER,  -- n
  publicExponent    INTEGER,  -- e
  privateExponent   INTEGER,  -- d
  prime1            INTEGER,  -- p
  prime2            INTEGER,  -- q
  exponent1         INTEGER,  -- d mod (p-1)
  exponent2         INTEGER,  -- d mod (q-1)
  coefficient       INTEGER,  -- (inverse of q) mod p
  otherPrimeInfos   OtherPrimeInfos OPTIONAL
}
*/
bool RSAPrivateKey::setKey( const char* buff, DWORD buffSize )
{
	if( buff == NULL || buffSize == 0 )
		return false;

	if( !eliminateHeader( buff, buffSize ) )
		return false;

	BYTE* decodedBuffer;
	DWORD decodedBuffSize;
	if( !base64Decode( buff, buffSize, decodedBuffer, decodedBuffSize ) )
		return false;

	BYTE* dataPtr = decodedBuffer;
	BYTE* endPtr = decodedBuffer + decodedBuffSize;
	DER_TLV der;

	// Expect SEQUENCE to start
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != SEQUENCE || der.length + (dataPtr - decodedBuffer) != decodedBuffSize )
		return false;

	// Expect VERSION
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	this->version = *der.value;
	dataPtr += der.length;

	// Expect modulus
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	setDER_Values( der, modulus, modulusSize );
	dataPtr += der.length;

	// Expect public exponent
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	setDER_Values( der, publicExponent, publicExponentSize );
	dataPtr += der.length;

	// Expect private exponent
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	setDER_Values( der, privateExponent, privateExponentSize );
	dataPtr += der.length;

	// Expect prime1
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	setDER_Values( der, prime1, prime1Size );
	dataPtr += der.length;

	// Expect prime2
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	setDER_Values( der, prime2, prime2Size );
	dataPtr += der.length;

	// Expect exponent1
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	setDER_Values( der, exponent1, exponent1Size );
	dataPtr += der.length;

	// Expect exponent2
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	setDER_Values( der, exponent2, exponent2Size );
	dataPtr += der.length;

	// Expect coefficient
	if( !readDER_TLV( dataPtr, der ) || der.tag.tag != INTEGER )
		return false;
	setDER_Values( der, coefficient, coefficientSize );
	dataPtr += der.length;

	return true;
}