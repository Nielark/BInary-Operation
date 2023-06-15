#include <iostream>
#include <cstdlib>

void menu();
void rotateRight(int arrBinary[], int numRot, int arrSize);
void rotateLeft(int arrBinary[], int numRot, int arrSize);
void shiftRight(int arrBinary[], int numShift, int arrSize);
void shiftLeft(int arrBinary[], int numShift, int arrSize);
void displayResult(int arrBinary[], int arrSize);

using namespace std;

int main()
{
    int numRot, numShift, arrSize, choice;

    start:
    cout << "Binary Digits Operation\n\n";

    cout << "Enter the number of binary: ";
    cin >> arrSize;
    int arrBinary[arrSize];     // Set the size for the array from the user input

    cout << "Enter " << arrSize <<" binary digits: ";
    for(int i = 0; i < arrSize; i++){         // Ask for the binary digits
        cin >> arrBinary[i];            // Stores the binary in the array
    }

    // Checks if elements of the array is a binary
    for(int i = 0; i < arrSize; i++){
        if(arrBinary[i] != 0 && arrBinary[i] != 1){
            cout << "Invalid input\n";
            break;
        }
    }

    menu();     // Display the choices of operations

    // Ask what operation to execute to the binary
    cout << "Enter the operation to apply: ";
    cin >> choice;

    switch(choice){
        case 1:
            // Ask how many times the binary will rotate
            cout << "Enter the number of rotations: ";
            cin >> numRot;

            rotateRight(arrBinary, numRot, arrSize);
            break;

        case 2:
            // Ask how many times the binary will rotate
            cout << "Enter the number of rotations: ";
            cin >> numRot;

            rotateLeft(arrBinary, numRot, arrSize);
            break;

        case 3:
            // Ask how many times the binary will shift to the right
            cout << "Enter the number of shift: ";
            cin >> numShift;

            shiftRight(arrBinary, numShift, arrSize);
            break;

        case 4:
            // Ask how many times the binary will shift to the left
            cout << "Enter the number of shift: ";
            cin >> numShift;

            shiftLeft(arrBinary, numShift, arrSize);
            break;

        default:
            cout << "Invalid Input\n";
    }

    // Initialize the values back to zero(0)
    numRot = 0;
    numRot = 0;
    numShift = 0;
    arrSize = 0;

    system("PAUSE");
    system("CLS");
    goto start;

    return 0;
}

void menu(){
    cout << endl;
    cout << "[1] - ROTATE RIGHT\n";
    cout << "[2] - ROTATE LEFT\n";
    cout << "[3] - SHIFT RIGHT\n";
    cout << "[4] - SHIFT LEFT\n\n";
}

void rotateRight(int arrBinary[], int numRot, int arrSize){
    int lIndexHold;

    // Outer loop for the number of rotations
    for(int i = 0; i < numRot; i++){
        lIndexHold = arrBinary[arrSize - 1];  // Store the value of the last index.

        // Inner loop for shifting the elements of the array
        for(int j = arrSize; j > 0; j--){
            arrBinary[j] = arrBinary[j - 1];    // Shift position of every element to the right
        }

        arrBinary[0] = lIndexHold;      // Move the past value of the last index to the first index

        // Display the result
        displayResult(arrBinary, arrSize);
        cout << endl;
    }
}

void rotateLeft(int arrBinary[], int numRot, int arrSize){
    int fIndexHold;

    // Outer loop for the number of rotations
    for(int i = 0; i < numRot; i++){
        fIndexHold = arrBinary[0];  // Store the value of the first index.

        // Inner loop for shifting the elements of the array
        for(int j = 0; j < arrSize; j++){
            arrBinary[j] = arrBinary[j + 1];    // Shift position of every element to the left
        }

        arrBinary[arrSize - 1] = fIndexHold;      // Move the past value of the first index to the last index

        // Display the result
        displayResult(arrBinary, arrSize);
        cout << endl;
    }
}

void shiftRight(int arrBinary[], int numShift, int arrSize){
    // Outer loop for the number of shift
    for(int i = 0; i < numShift; i++){
        // Inner loop for the shifting of element to the right
        for(int j = arrSize; j > 0; j--){
           arrBinary[j] = arrBinary[j - 1];     // Shift the position of every element to the right
        }

        arrBinary[i] = 0;   // Change the values of the MSB to zero (0)

        // Display the result
        displayResult(arrBinary, arrSize);
        cout << endl;
    }
}

void shiftLeft(int arrBinary[], int numShift, int arrSize){
    // Outer loop for the number of shift
    for(int i = 0; i < numShift; i++){
        // Inner loop for the shifting of element to the left
        for(int j = 0; j < arrSize; j++){
           arrBinary[j] = arrBinary[j + 1];     // Shift the position of every element to the left
        }

        arrBinary[arrSize - 1] = 0;   // Change the values of the LSB to zero (0)

        // Display the result
        displayResult(arrBinary, arrSize);
        cout << endl;
    }
}

void displayResult(int arrBinary[], int arrSize){
    // Displays the rotated binary
    for(int i = 0; i < arrSize; i++){
        cout << arrBinary[i];
    }
}
