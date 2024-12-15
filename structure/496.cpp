#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 10;

struct Image {
    int width;
    int height;
    int data[MAX_SIZE][MAX_SIZE];
};

void rotateImage(Image& img, int degrees) {
    int temp[MAX_SIZE][MAX_SIZE];
    int newWidth, newHeight;

    if (degrees == 0 || degrees == 360) {
        newWidth = img.width;
        newHeight = img.height;
    } else if (degrees == 90 || degrees == 270) {
        newWidth = img.height;
        newHeight = img.width;
    } else if (degrees == 180) {
        newWidth = img.width;
        newHeight = img.height;
    } else {
        cout << "Invalid rotation angle." << endl;
        return;
    }

    // Copy the original image data to a temporary array
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            temp[i][j] = img.data[i][j];
        }
    }

    // Rotate the image data based on the specified angle
    if (degrees == 90 || degrees == 270) {
        for (int i = 0; i < newHeight; i++) {
            for (int j = 0; j < newWidth; j++) {
                if (degrees == 90) {
                    img.data[i][j] = temp[img.height - 1 - j][i];
                } else {
                    img.data[i][j] = temp[j][img.width - 1 - i];
                }
            }
        }
    } else if (degrees == 180) {
        for (int i = 0; i < newHeight; i++) {
            for (int j = 0; j < newWidth; j++) {
                img.data[i][j] = temp[newHeight - 1 - i][newWidth - 1 - j];
            }
        }
    } else {
        // No rotation needed
        for (int i = 0; i < newHeight; i++) {
            for (int j = 0; j < newWidth; j++) {
                img.data[i][j] = temp[i][j];
            }
        }
    }

    // Update the image width and height
    img.width = newWidth;
    img.height = newHeight;
}

int main() {
    Image img;
    int degrees;

    // Input image width and height
    cin >> img.width >> img.height;

    // Input image data
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            cin >> img.data[i][j];
        }
    }

    // Input rotation angle
    cin >> degrees;

    // Rotate the image
    rotateImage(img, degrees);

    // Output the rotated image
    cout << img.width << " " << img.height << endl;
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            cout << img.data[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
