#include "Image.h"
using namespace std;

// #define MAIN_TEST

int main(int argc, char** argv) {
#ifndef MAIN_TEST    
    string inputImage;
    int rowSize;
    
    // gain user input
    if (argc == 3) {
        inputImage  = argv[1];
        rowSize = stoi(argv[2],nullptr,10);
    } else {
        cout << "Please input image in one dimension:" <<endl;
        getline(cin, inputImage);
        cout << "Please input image row length:" <<endl;
        cin >> rowSize;
    }

    //output origianl image and flipped image
    Image image(inputImage, rowSize);
    cout<<"Original image:" <<endl;
    image.printImage();
    image.imageFlip();
    cout<<"Flipped image: " <<endl;
    image.printImage();

// some base tests
#else
    /* test 1 with default example */
    Image *imageDefault = new Image();
    cout<<"Original image: " <<endl;
    imageDefault->printImage();
    imageDefault->imageFlip();
    cout<<"Flipped image: " <<endl;
    imageDefault->printImage();
    delete imageDefault;

    /* test 2 with second constructor Image(string, int) */
    Image image2("abcdefg", 5);
    cout<<"Original image: " <<endl;
    image2.printImage();
    image2.imageFlip();
    cout<<"Flipped image: " <<endl;
    image2.printImage();

    /* test 3 with second constructor Image(string, int) */
    Image image3("abcdefg", 20);
    cout<<"Original image: " <<endl;
    image3.printImage();
    image3.imageFlip();
    cout<<"Flipped image: " <<endl;
    image3.printImage();

    /* test 4 with second constructor Image(string, int) */
    Image image4("123456", 20);
    cout<<"Original image: " <<endl;
    image4.printImage();
    image4.imageFlip();
    cout<<"Flipped image: " <<endl;
    image4.printImage();
    image4.imageFlip();
    cout<<"Flipped flipped image: " <<endl;
    image4.printImage();
    return 0;
#endif /* MAIN_TEST */
}
