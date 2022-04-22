#pragma once
#include <istream>
#include "Sequence.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Complex.h"
#include <vector>
#include "Vector.h"
#include <fstream>
#include <string>

#ifndef LAB2_TEST_H
#define LAB2_TESTR_H




int SumEquals(void * m1, void * m2, size_t size, int n){
    if (memcmp(m1, m2, size * n) == 0){
        return 1;
    }
    return 0;
}

int GenInt(){
    return rand() % 1000;;
}

float Genfloat(){
    return ((float)(rand() % 10000)) / 100;
}

template <typename T>
ComplexNumber<T> GenComplex(){
    return ComplexNumber<T>(rand() % 1000, rand() % 1000);
}

template <typename T>
std::ostream& operator << (std::ostream &out, vector<T> &vec)
{
    if (vec.size() == 0){
        out << "{}";
        return out;
    }
    out << "{";
    for (int i = 0; i < vec.size() - 1; i++){
        out << vec[i] << ", ";
    }
    if (vec.size() > 0){
        out << vec[vec.size() - 1];
    }
    out << "}";
    return out;
}

template <typename T>
std::ostream& operator << (std::ostream &out, ArraySequence<T> &arr)
{
    if (arr.GetLength() == 0){
        out << "{}";
        return out;
    }
    out << "{";
    for (int i = 0; i < arr.GetLength() - 1; i++){
        out << arr.Get(i) << ", ";
    }
    if (arr.GetLength() > 0){
        out << arr.Get(arr.GetLength() - 1);
    }
    out << "}";
    return out;
}

template <typename T>
std::ostream& operator << (std::ostream &out, LinkedListSequence<T> &list)
{
    if (list.GetLength() == 0){
        out << "{}";
        return out;
    }
    out << "{";
    for (int i = 0; i < list.GetLength() - 1; i++){
        out << list.Get(i) << ", ";
    }
    if (list.GetLength() > 0){
        out << list.Get(list.GetLength() - 1);
    }
    out << "}";
    return out;
}


//Test of vector
template <typename T>
void Test_Vector(T (*generate)(), string FileName){
    ofstream fout(FileName + ".txt");
    for (int i = 1; i < 30; i++){
        Vector<T> myVector1 = Vector<T>();
        Vector<T> myVector2 = Vector<T>();
        vector<T> sumVector;
        Vector<T> MySumVector = Vector<T>();

        T number1 = generate();
        T number2 = generate();
        myVector1.Append(number1);
        myVector2.Append(number2);
        sumVector.push_back(number1 + number2);
        T ScalarMult = number1 * number2;
        T Norm1 = number1 * number1;
        T Norm2 = number2 * number2;
        for (int j = 1; j < i; j++){
            number1 = generate();
            number2 = generate();
            myVector1.Append(number1);
            myVector2.Append(number2);
            sumVector.push_back(number1 + number2);

            ScalarMult = ScalarMult + (number1 * number2);
            Norm1 = Norm1 + (number1 * number1);
            Norm2 = Norm2 + (number2 * number2);
        }

        MySumVector = myVector1 + myVector2;
        T MyScalar = myVector1 * myVector2;
        int result = 1;
        for (int element = 0; element < i; element++) {
            if (!(sumVector[element] == MySumVector[element]) || (!(MyScalar == ScalarMult)) || (!(Norm1 == myVector1.Norm()) || (!(Norm2 == myVector2.Norm())))) {
                result = 0;
            }
        }
        fout << "|||||||||||||||||||||||||||||||| ";
        if (result) {
            fout << "Test " + to_string(i) << " OK";
        }
        else {
            fout << "Test " + to_string(i) << " FAIL";
        }
        fout << " ||||||||||||||||||||||||||||||||" << endl;

        fout << "Vectors: \n";
        fout << "V1: " << myVector1 << endl;
        fout << "V2: " << myVector2 << endl;
        fout << "RV: ";
        fout << MySumVector << endl;
        fout << "MV: ";
        fout << sumVector << endl;
        fout << "RSM: " << ScalarMult  << endl;
        fout << "MSM: " << MyScalar  << endl;
        fout << "__Norms: " << Norm1 << " " << Norm2 << endl;
        fout << "MyNorms: " << myVector1.Norm() << " " << myVector2.Norm() << endl;
        fout << endl;
    }
    fout.close();


}


//test of ArraySequence
template <typename T>
void Test_ArraySequence_LinkedListSequence(T (*generate)(), string FileName){
    ofstream fout(FileName + ".txt");
    for (int i = 1; i < 30; i++){
        ArraySequence<T> arrSeq = ArraySequence<T>();
        LinkedListSequence<T> linListSeq = LinkedListSequence<T>();
        vector<T> NVector;

        for (int j = 0; j < i; j++){
            T number = generate();
            arrSeq.Append(number);
            linListSeq.Append(number);
            NVector.push_back(number);
        }

        int result = 1;
        for (int element = 0; element < i; element++) {
            if (!(arrSeq.Get(element) == linListSeq.Get(element)) || !(arrSeq.Get(element) == NVector[element]) || !(NVector[element] == linListSeq.Get(element))) {
                result = 0;
            }
        }
        fout << "|||||||||||||||||||||||||||||||| ";
        if (result) {
            fout << "Test " + to_string(i) << " OK";
        }
        else {
            fout << "Test " + to_string(i) << " FAIL";
        }
        fout << " ||||||||||||||||||||||||||||||||" << endl;

        fout << "_____ArraySequence: " << arrSeq << endl;
        fout << "LinkedListSequence: " << linListSeq << endl;
        fout << "____________Vector: " << NVector << endl;
        fout << "GetFirst: " << arrSeq.GetFirst() << " " << linListSeq.GetFirst() << " " << NVector[0] << endl;
        fout << "_GetLast: " << arrSeq.GetLast() << " " << linListSeq.GetLast() << " " << NVector[NVector.size() - 1] << endl;
        fout << "Get " << NVector.size() / 2 << " element: " << arrSeq.Get(NVector.size() / 2) << " " << linListSeq.Get(NVector.size() / 2) << " " << NVector[NVector.size() / 2] << endl;

        fout << endl;

        T element = generate();
        fout << "InsertAt " << NVector.size() / 2 << " position element " << element << ": " << endl;
        arrSeq.InsertAt(element, NVector.size() / 2);
        linListSeq.InsertAt(element, NVector.size() / 2);
        NVector.insert(NVector.begin() + NVector.size() / 2, element);
        fout << "New_____ArraySequence: " << arrSeq << endl;
        fout << "NewLinkedListSequence: " << linListSeq << endl;
        fout << "New____________Vector: " << NVector << endl;

        fout << endl;

        int place = rand() % NVector.size();
        fout << "Remove element in " << place <<  " position: " << endl;
        arrSeq.Delete(place);
        linListSeq.Delete(place);
        NVector.erase(NVector.begin() + place);
        fout << "New_____ArraySequence: " << arrSeq << endl;
        fout << "NewLinkedListSequence: " << linListSeq << endl;
        fout << "New____________Vector: " << NVector << endl;

        fout << endl;

        int start = 0;
        int end = 0;
        if (NVector.size() < 2){
            start = 0;
            end = 1;
        } else {
            start = rand() % (NVector.size() / 2);
            end = (rand() % (NVector.size() / 2)) + (NVector.size() / 2);
        }
        fout << "GetSubSequence, (startI = " << start << ", endI = " << end << ") : " << endl;
        fout << "New_____ArraySequence: " << *arrSeq.GetSubSequence(start, end) << endl;
        fout << "NewLinkedListSequence: " << *linListSeq.GetSubSequence(start, end) << endl;
        fout << "New____________vector: ";
        fout << "{";
        for (int p = start; p < end - 1; p++){
            fout << NVector[p] << ", ";
        }
        if (NVector.size() > end - 1){
            fout << NVector[end - 1];
        }
        fout << "}" << endl;

        fout << endl;

        fout << "Current Array: " << arrSeq << endl;
        ArraySequence<T> TimeArray = ArraySequence<T>();
        T n1 = generate(), n2 = generate(), n3 = generate();
        TimeArray.Append(n1);
        TimeArray.Append(n2);
        TimeArray.Append(n3);
        vector<T> tv = {n1, n2, n3};
        fout << "Concatenate with " << TimeArray << endl;
        fout << "New_____ArraySequence: " << *arrSeq.Concatenate(TimeArray) << endl;
        fout << "NewLinkedListSequence: " << *linListSeq.Concatenate(TimeArray) << endl;
        NVector.insert( NVector.end(), tv.begin(), tv.end() );
        fout << "New____________vector: " << NVector << endl;

        fout << endl;

    }
    fout.close();


}


#endif


