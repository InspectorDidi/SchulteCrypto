// Driver.cpp : Defines the entry point for the console application.
//

#include "DriverAES.h"
#include "../RSALib/RSAPublicKey.h"
#include "../RSALib/RSAPrivateKey.h"

#include <stdio.h>

#pragma comment(lib, "RSALib.lib")

#define MSG_SUC "Success!"
#define MSG_FAL "___FAILED___!"

int DriverRSA()
{
// 	BigNum test1( "AB" );
// 	BigNum test2( "CDEF" );
// 	char test1a[10], test2a[10];
// 	DWORD test1aSize = 10, test2aSize = 10;
// 	test1.toArray( test1a, test1aSize);
// 	test2.toArray( test2a, test2aSize );
// 
// 	RSAPublicKey r;
// 	r.modulus.initialize( "CA1" ); // 3233
// 	r.publicExponent.initialize( "11" ); // 17
// 
// 	BigNum plainText( "41" ); //65
// 	BigNum cipherText = r.cipher( plainText );
// 
// 	// Test if successful
// 	BigNum result( "AE6" );
// 	if( !(cipherText == result) )
// 	{
// 		puts( "Error encrypting" );
// 		return -1;
// 	}
// 
// 	RSAPrivateKey p;
// 	p.modulus.initialize( "CA1" ); //3233
// 	p.privateExponent.initialize( "AC1" ); // 2753
// 
// 	BigNum one( "1" );
// 	p.prime1.initialize( "3D" ); // 61
// 	p.prime2.initialize( "35" ); // 53
// 	p.exponent1 = p.privateExponent % (p.prime1 - one); // should be 53
// 	p.exponent2 = p.privateExponent % (p.prime2 - one); // should be 49
// 	p.coefficient = p.prime2.modInverse( p.prime1 );    // should be 38
// 
// 	BigNum plaintTextDecrypted = p.decipher( cipherText );
// 
// 	// Test if successful
// 	if( !(plaintTextDecrypted == plainText) )
// 	{
// 		puts( "Error decrypting");
// 			return -2;
// 	}
// 	return  0;


	char szMod[] = "F0C42DB8486FEB9595D8C78F908D04A9B6C8C77A36105B1BF2755377A6893DC4383C54EC6B5262E5688E5F9D9DD16497D0E3EA833DEE2C8EBCD1438389FCCA8FEDE7A88A81257E8B2709C494D42F723DEC2E0B5C09731C550DCC9D7E752589891CBBC3021307DD918E100B34C014A559E0E182AFB21A72B307CC395DEC995747";
	char szPubExp[] = "010001";
	char szPrivExp[] = "2489108B0B6AF86BED9E44C2336442D5E227DBA55EF8E26A7E437194119077F003BC9C027852BB3126C99C16D5F1057BC8361DCB26A5B2DB4229DB3DE5BD979B2E597D1916D7BBC92746FC07595C76B44B39A476A65C86F086DC9283CA6D1EEFC14915982F9C4CED5F62A9FF3BE24218A99357B5B65C3B10AEB367E911EB9E21";
	char szP[] = "fcdd262bb1b8167ffe230bc9ff01e2a00061c51b58ed359e9f55721b90e75c46d3c7568ce6293eb958a87482135103c36112dcd3f1d3833b4df45480937d8c77";
	char szQ[] = "f3c09e9178a19eb224ce071d87c722321767e3e98f0df00e308df0eaf68c23818d541bb30d80fc0999415a4264a63c1ddb5eb0bee49994a75401e3765c41cfb1";
	char szExp1[] = "3d21a9ecbe5666fa22928e7313377d76792129e9e6a1d268bad48975a89e866c891e940a144abc634acfcefaf3788e94598f99db9387331ecf45d6780f303719";
	char szExp2[] = "d6b83036cf3ff7eecf931a1b7e57019d8496c4e3225c51c1fe2d9b332fba2530e3515b11306d161852838a42002d9bb9655c15702329d3144f6156811625f711";
	char szCoeff[] = "99b7e834885e52d7cdeaed20b04d94a29908cfb5f0c34c7177f331b1845beb93c5cfe062508ee5ad2d4dd30d7a21fbc7af08d7f008ef5f8b7e188882b9386863";

	BYTE inputCipher[] = { 0x11, 0x22, 0x33, 0x44 };
	BYTE pubExp[] = { 0x01, 0x00, 0x01 };
	BYTE privExp[] = { 0x24, 0x89, 0x10, 0x8B, 0x0B, 0x6A, 0xF8, 0x6B, 0xED, 0x9E, 0x44, 0xC2, 0x33, 0x64, 0x42, 0xD5, 0xE2, 0x27, 0xDB, 0xA5, 0x5E, 0xF8, 0xE2, 0x6A, 0x7E, 0x43, 0x71, 0x94, 0x11, 0x90, 0x77, 0xF0, 0x03, 0xBC, 0x9C, 0x02, 0x78, 0x52, 0xBB, 0x31, 0x26, 0xC9, 0x9C, 0x16, 0xD5, 0xF1, 0x05, 0x7B, 0xC8, 0x36, 0x1D, 0xCB, 0x26, 0xA5, 0xB2, 0xDB, 0x42, 0x29, 0xDB, 0x3D, 0xE5, 0xBD, 0x97, 0x9B, 0x2E, 0x59, 0x7D, 0x19, 0x16, 0xD7, 0xBB, 0xC9, 0x27, 0x46, 0xFC, 0x07, 0x59, 0x5C, 0x76, 0xB4, 0x4B, 0x39, 0xA4, 0x76, 0xA6, 0x5C, 0x86, 0xF0, 0x86, 0xDC, 0x92, 0x83, 0xCA, 0x6D, 0x1E, 0xEF, 0xC1, 0x49, 0x15, 0x98, 0x2F, 0x9C, 0x4C, 0xED, 0x5F, 0x62, 0xA9, 0xFF, 0x3B, 0xE2, 0x42, 0x18, 0xA9, 0x93, 0x57, 0xB5, 0xB6, 0x5C, 0x3B, 0x10, 0xAE, 0xB3, 0x67, 0xE9, 0x11, 0xEB, 0x9E, 0x21 };
	BYTE rsaMod[] = { 0xF0, 0xC4, 0x2D, 0xB8, 0x48, 0x6F, 0xEB, 0x95, 0x95, 0xD8, 0xC7, 0x8F, 0x90, 0x8D, 0x04, 0xA9, 0xB6, 0xC8, 0xC7, 0x7A, 0x36, 0x10, 0x5B, 0x1B, 0xF2, 0x75, 0x53, 0x77, 0xA6, 0x89, 0x3D, 0xC4, 0x38, 0x3C, 0x54, 0xEC, 0x6B, 0x52, 0x62, 0xE5, 0x68, 0x8E, 0x5F, 0x9D, 0x9D, 0xD1, 0x64, 0x97, 0xD0, 0xE3, 0xEA, 0x83, 0x3D, 0xEE, 0x2C, 0x8E, 0xBC, 0xD1, 0x43, 0x83, 0x89, 0xFC, 0xCA, 0x8F, 0xED, 0xE7, 0xA8, 0x8A, 0x81, 0x25, 0x7E, 0x8B, 0x27, 0x09, 0xC4, 0x94, 0xD4, 0x2F, 0x72, 0x3D, 0xEC, 0x2E, 0x0B, 0x5C, 0x09, 0x73, 0x1C, 0x55, 0x0D, 0xCC, 0x9D, 0x7E, 0x75, 0x25, 0x89, 0x89, 0x1C, 0xBB, 0xC3, 0x02, 0x13, 0x07, 0xDD, 0x91, 0x8E, 0x10, 0x0B, 0x34, 0xC0, 0x14, 0xA5, 0x59, 0xE0, 0xE1, 0x82, 0xAF, 0xB2, 0x1A, 0x72, 0xB3, 0x07, 0xCC, 0x39, 0x5D, 0xEC, 0x99, 0x57, 0x47 };

	BigNum plainText;
	plainText.initialize( sizeof( inputCipher ) * 2, inputCipher, false );

	RSAPublicKey p;
	p.publicExponent.initialize( sizeof( pubExp ) * 2, pubExp, false );
	p.modulus.initialize( sizeof( rsaMod ) * 2, rsaMod, false );
	BigNum cipherText = p.cipher( plainText );

	char test1a[1024];
	DWORD test1aSize = 1024;
	cipherText.toArray( test1a, test1aSize );

	char ct[] = "505B09BD5D0E66D7C8829F5B473ED34DB5CFDBB5D58CE78329C8BF8520E486D3C4CF9B70C6346594358080F43F47EE863CFAF2A2E5F03D1E13D6FEC57DFB1D552224C461DA411CFE5D0B05BA877E3A42F6DE4DA46A965C9B695EE2D50E400894061CB0A21CA3A524B407E9FFBA87FC966B3BA94590849AEB908AAFF4C719C2E4";
// 	if( strcmp( test1a, ct ) != 0 )
// 	{
// 		puts("Error encrypting")
// 	}

	BYTE output[] = { 0x50, 0x5B, 0x09, 0xBD, 0x5D, 0x0E, 0x66, 0xD7, 0xC8, 0x82, 0x9F, 0x5B, 0x47, 0x3E, 0xD3, 0x4D, 0xB5, 0xCF, 0xDB, 0xB5, 0xD5, 0x8C, 0xE7, 0x83, 0x29, 0xC8, 0xBF, 0x85, 0x20, 0xE4, 0x86, 0xD3, 0xC4, 0xCF, 0x9B, 0x70, 0xC6, 0x34, 0x65, 0x94, 0x35, 0x80, 0x80, 0xF4, 0x3F, 0x47, 0xEE, 0x86, 0x3C, 0xFA, 0xF2, 0xA2, 0xE5, 0xF0, 0x3D, 0x1E, 0x13, 0xD6, 0xFE, 0xC5, 0x7D, 0xFB, 0x1D, 0x55, 0x22, 0x24, 0xC4, 0x61, 0xDA, 0x41, 0x1C, 0xFE, 0x5D, 0x0B, 0x05, 0xBA, 0x87, 0x7E, 0x3A, 0x42, 0xF6, 0xDE, 0x4D, 0xA4, 0x6A, 0x96, 0x5C, 0x9B, 0x69, 0x5E, 0xE2, 0xD5, 0x0E, 0x40, 0x08, 0x94, 0x06, 0x1C, 0xB0, 0xA2, 0x1C, 0xA3, 0xA5, 0x24, 0xB4, 0x07, 0xE9, 0xFF, 0xBA, 0x87, 0xFC, 0x96, 0x6B, 0x3B, 0xA9, 0x45, 0x90, 0x84, 0x9A, 0xEB, 0x90, 0x8A, 0xAF, 0xF4, 0xC7, 0x19, 0xC2, 0xE4 };
	BigNum out( sizeof( output ) * 2, output, false );
	if( !(out == cipherText) )
	{
		puts( "Error: encryption failed" );
		return -1;
	}
	puts( "Encryption succeeded!" );

	RSAPrivateKey priv;
	priv.privateExponent.initialize( sizeof( privExp ) * 2, privExp, false );
	priv.modulus.initialize( sizeof( rsaMod ) * 2, rsaMod, false );

	priv.prime1.initialize( szP );
	priv.prime2.initialize( szQ );
	priv.exponent1.initialize( szExp1 );
	priv.exponent2.initialize( szExp2 );
	priv.coefficient.initialize( szCoeff );

	BigNum plainText2 = priv.decipher( cipherText );
	if( !(plainText2 == plainText) )
	{
		puts( "Error: decryption failed" );
		return -2;
	}
	puts( "Decryption succeeded!" );

	return 0;
}