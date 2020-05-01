/*                                                                              
 *  Filename: bin.cc                                                          
 *  Date: April 30 2020                                                           
 *  Author: Ism Khadka                                                          
 *  Email: ixk180000@utdallas.edu                                               
 *  Course: CS 3377.501                                                         
 *  Version: 1.0                                                                
 *  Copyright 2020, All Rights Reserved                                         
 *                                                                              
 *  Description:                                                                
 *                   Reads the binary file                                                           
 *                                                                              
 */
#include <sstream>
#include <iostream>
#include <stdint.h>
#include <fstream>
#include <cstring> 	// for memset()
#include <string>
#include "cdk.h"
#include "bin.h"
using namespace std;

//
// Record with fields


	
const int maxRecordSLength = 25;
class BinaryFileHeader{
public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

class BinaryFileRecord{
public:
  uint8_t strLength;
  char  stringBuffer[maxRecordSLength];
};

void binary(CDKMATRIX* myMatrix)
{
  ifstream binInfile;
  BinaryFileHeader *myHeader = new BinaryFileHeader();
  BinaryFileRecord *myRecord = new BinaryFileRecord();

  binInfile.open ("/scratch/perkins/cs3377.bin", ios::in | ios::binary);
  if(!binInfile.is_open()){
    cout << "Error cannot find the file" << endl<< endl << endl;
  }
  else{
    stringstream text;
    string output;
    text.str("");
    binInfile.read((char *) myHeader, sizeof(BinaryFileHeader));
    text<<"Magic: 0x" << hex << uppercase << myHeader->magicNumber;
    output = text.str();
    text.str("");
    setCDKMatrixCell(myMatrix, 1, 1, output.c_str());
    text << "Version: "<< dec << myHeader->versionNumber;
    output = text.str();
    text.str("");
    setCDKMatrixCell(myMatrix, 1, 2,output.c_str());
    text << "NumRecords: "<< dec <<  myHeader->numRecords;
    output = text.str();
    text.str("");
    setCDKMatrixCell(myMatrix, 1, 3,output.c_str());
    
    int num = myHeader->numRecords;
    
    
    for(int i = 0; i <num; i++){
      binInfile.read((char *) myRecord, sizeof(BinaryFileRecord));
      text << "strlen : "<< (int) myRecord->strLength;
      output = text.str();
      text.str("");
      setCDKMatrixCell(myMatrix, i+2, 1,output.c_str());
      setCDKMatrixCell(myMatrix, i+2, 2,myRecord->stringBuffer);
      
    }

    binInfile.close();
    delete myHeader;
    delete myRecord;
  }
}

