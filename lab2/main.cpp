#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include "Sequence.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Vector.h"
#include "Complex.h"
#include "malloc.h"
#include "tests.h"




using namespace std;

template <typename T>
Vector<T> read(){
    int N;
    Vector<T> vec = Vector<T>();
    cout << "Write size: ";
    cin >> N;

    for (int i = 0; i < N; i++){
        T el;
        cin >> el;
        vec.Append(el);
    }
    return vec;
}




template <typename T>
void init(Vector<T> vector1, Vector<T> vector2){
    while (true){
        cout << "1 - write vectors\n";
        cout << "2 - sum vectors\n";
        cout << "3 - diff vectors\n";
        cout << "4 - mult vectors by a scalar\n";
        cout << "5 - vectors norms\n";
        cout << "6 - scalar mult vectors\n";
        cout << "7 - split\n";
        cout << "8 - exit\n";
        int action;
        cin >> action;
        if (action == 1){
            cout << vector1 << endl;
            cout << vector2 << endl;
        }
        if (action == 2){
            Vector<T> vec =  vector1 + vector2;
            cout << vec << endl;
        }
        if (action == 3){
            Vector<T> vec =  vector1 - vector2;
            cout << vec << endl;
        }
        if (action == 4){
            cout << "write k1 and k2: ";
            int k1;
            cin >> k1;
            int k2;
            cin >> k2;
            vector1.ScalarMult(k1);
            vector2.ScalarMult(k2);
        }
        if (action == 5){
            cout << vector1.Norm() << endl;
            cout << vector2.Norm() << endl;
        }
        if (action == 6){
            cout << vector1 * vector2 << endl;
        }
        if (action == 7){
            T number;
            cout << "Print split number: ";
            cin >> number;
            Vector<Vector<T>> first = vector1.Split(number);
            cout << first << endl;
            Vector<Vector<T>> second = vector2.Split(number);
            cout << second << endl;
        }
        if (action == 8){
            return;
        }
    }


}

int main() {
    srand(time(NULL));


    cout << "input(0)/random(1)/test(2)?\n";
    int action;
    cin >> action;

    cout << "int(0)/float(1)/complex(2)?\n";
    int type;
    cin >> type;
    if (action == 0){
        if (type == 0){
            Vector<int> vector1;
            Vector<int> vector2;
            if (action == 0){
                vector1 = read<int>();
                vector2 = read<int>();
            }
            init(vector1, vector2);
        }
        else if (type == 1){
            Vector<float> vector1;
            Vector<float> vector2;
            if (action == 0){
                vector1 = read<float>();
                vector2 = read<float>();
            }
            init(vector1, vector2);
        } else{
            Vector<ComplexNumber<int>> vector1;
            Vector<ComplexNumber<int>> vector2;
            if (action == 0){
                vector1 = read<ComplexNumber<int>>();
                vector2 = read<ComplexNumber<int>>();
            }
            init(vector1, vector2);
        }
    } else if (action == 1) {
        if (type == 0){
            Vector<int> vector1;
            Vector<int> vector2;
            int N;
            cout << "Write size: ";
            cin >> N;
            for (int i = 0; i < N; i++){
                int el;
                el = rand() % 1000;
                vector1.Append(el);
                el = rand() % 1000;
                vector2.Append(el);
            }
            init(vector1, vector2);
        }
        else if (type == 1){
            Vector<float> vector1;
            Vector<float> vector2;
            int N;
            cout << "Write size: ";
            cin >> N;
            for (int i = 0; i < N; i++){
                float el;
                el = ((float)(rand() % 10000)) / 100;
                vector1.Append(el);
                el = ((float)(rand() % 10000)) / 100;
                vector2.Append(el);
            }
            init(vector1, vector2);
        } else{
            Vector<ComplexNumber<int>> vector1;
            Vector<ComplexNumber<int>> vector2;
            int N;
            cout << "Write size: ";
            cin >> N;
            for (int i = 0; i < N; i++){
                ComplexNumber<int> el(rand() % 1000, rand() % 1000);
                vector1.Append(el);
                ComplexNumber<int> el2(rand() % 1000, rand() % 1000);
                vector2.Append(el2);
            }
            init(vector1, vector2);
        }
    }
    else {
        Test_Vector<ComplexNumber<int>>(GenComplex, "complexTest");
        Test_Vector<int>(GenInt, "intTest");
        Test_Vector<float>(Genfloat, "floatTest");
        cout << "Check: complexTest.txt, intTest.txt, floatTest.txt\n";

        Test_ArraySequence_LinkedListSequence(GenInt, "intArrListTest");
        Test_ArraySequence_LinkedListSequence(Genfloat, "floatArrListTest");
        Test_ArraySequence_LinkedListSequence(GenComplex<int>, "complexArrListTest");
        cout << "Check: intArrListTest.txt, floatArrListTest.txt, complexArrListTest.txt\n";

    }
    //split


    return 0;
}
