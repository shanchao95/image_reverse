#include "Image.h"
using namespace std;

// #define USING_SWAP_FUNC
// #define DEBUG

/* default constructor, initilaize the values to example of chanllenge c++ */
Image::Image() {
    image = "++++C+++C+++C+++C+++C+++++C+++++C+++++C+++++C";
    rowSize = 5;
}

/* image constructor with input image data of string, and length of each row in image */ 
Image::Image(string str, int rowSize) {
    if (rowSize < 1) {
        cerr<< "ERROR: row length must be greater than 0, default image was created!" <<endl;
        image = "++++C+++C+++C+++C+++C+++++C+++++C+++++C+++++C";
        this->rowSize = 5;
    } else {
        image = str;
        this->rowSize = rowSize;
    } 
    
}

/*
   flip the image by vertical axis
   Note: after flipping image, the image size may be changed if it gets padding with ' '  
*/
void Image::imageFlip() {
    int padSize = image.length() % rowSize == 0? 0 : rowSize - image.length() % rowSize;
    if (padSize != 0) {

#ifdef DEBUG
        string padStr (padSize, '*');
#else
        string padStr (padSize, ' ');
#endif /* DEBUG */

        image += padStr; 
    }
    for (int i = 0; i < image.length() / rowSize; i++) {
            swapBetween(i*rowSize, (i+1) * rowSize - 1);
    }
    return;
}

/* draw image */
void Image::printImage() {
    for (int i = 0; i < image.length(); i++) {
        cout<< image[i];
        if (i % rowSize == rowSize-1 || i == image.length() - 1) {
            cout<<endl;
        }
    }
    return;
}


#define USING_SWAP_FUNC
/* swap between an interval, ex. 1234 -> 4321 */
void Image::swapBetween(int start, int end) {
#ifdef USING_SWAP_FUNC
    while (start < end) {
            swap(image[start++], image[end--]);
        }
#else 
    char* leftPtr = const_cast<char*>(image.c_str()) + start;
    char* rightPtr = const_cast<char*>(image.c_str()) + end;
    char temp;
    while (leftPtr < rightPtr) {
        temp = *leftPtr;
        *leftPtr = *rightPtr;
        *rightPtr = temp;
        leftPtr++;
        rightPtr--;
    }
#endif /* USING_SWAP_FUNC */
}
