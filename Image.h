#pragma once
#include <iostream>
#include <string>
using namespace std;

class Image {
    private:

    string image;
    int rowSize;

    public:

    /* default constructor, initilaize the values to example of chanllenge c++ */
    Image();

    /* 
       image constructor with input image data of string, and length of each row in image
       str: input image in a type of string
       rowSize: length of the image in each row
    */
    Image(string str, int rowSize);

    /* flip image by vertical axis */
    void imageFlip();

    /* draw image */
    void printImage();

    private:

    /* swap between an interval, ex. 1234 -> 4321 */
    void swapBetween(int start, int end);
};
