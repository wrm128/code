#include "zigzag.h"
using namespace std;

void testShift()
{
    int n,c;
    cout << "Input number: " ;
    cin >> n;
    cout << "Shift bits: ";
    cin >> c;
    cout << "Left shift: " << (n << c) << endl;
    cout << "Right shift: " << (n >> c) << endl;
    string comment = "when left shift x bits, add x 0 at the right end; ";
    comment += "when right shift x bits, use the sign bits to fill up at the left end.";
    cout << comment << endl;
}

int main()
{
    testShift();	
    int a[] = {24, (int)(-pow(2L,32)), -1000, -1, 0, 1, 1000, (int)(pow(2L, 31) - 1L), -24};
    int n = sizeof(a)/sizeof(int);
    vector<int> input(a, a+n);
    vector<byte> compress;
    vector<int> output;
    cout << "Input data: " << endl;
    for(int i=0; i<input.size(); ++i){
        cout << input[i] << ", ";
    }
    cout << endl;
    cout << "The total size of input data: " << sizeof(input) << " | " << input.size() << "*" << sizeof(int) << "=" << input.size()*sizeof(int) << endl;
    compressInt(input, compress);
    cout << "After compress, the size of input data: " << sizeof(compress) << " | " << compress.size() << "*" << sizeof(byte) << "=" << compress.size()*sizeof(byte) << endl;
    decompressInt(compress, output);
    cout << "After decompress, the data are as follows: " << endl;
    for(int i=0; i<output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;
	return 0;
}
