#pragma once
#include <istream>
//
// Created by user on 11.04.2022.
//

#include "Sequence.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Complex.h"

using namespace std;


#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H




template <class T>
class Vector {
private:
    Sequence<T>* vector;
    size_t size;
public:
    T& operator [] (int index){
        return vector->Get(index);
    }


    Vector (){
        vector = new ArraySequence<T>();
        //vector = new LinkedListSequence<T>();
        size = 0;
    }

    Vector (size_t n){
        vector = new ArraySequence<T>();
        for (int i = 0; i < n; i++){
            vector->Append(0);
        }
        //vector = new LinkedListSequence<T>();
        size = n;
    }

    Vector (Sequence<T>* sequence){
        vector = new ArraySequence<T>();
        for (int i = 0; i < sequence->GetLength(); i++){
            vector->Append(sequence->Get(i));
        }
        //vector = new LinkedListSequence<T>();
        size = sequence->GetLength();
    }



    void Append(T element){
        size++;
        vector->Append(element);
    }
    void Prepend(T element){
        size++;
        vector->Prepend(element);
    }

    void Print(){
        vector->PrintArray();
    }

    size_t GetLenth(){
        return size;
    }

    void ScalarMult(float number){
        for (int i = 0; i < vector->GetLength(); i++){
            vector->Set(number * (vector->Get(i)), i);
        }
    }

    T Norm(){
        if (vector->GetLength() <= 0){
            throw "Zero Vector";
        }
        T value = vector->Get(0) * vector->Get(0);
        for (int i = 1; i < vector->GetLength(); i++){
            value = (value + (vector->Get(i)) * (vector->Get(i)));
        }
        return value;
    }

    Vector<Vector<T>> Split(T element) {
        Vector<T> timeVec = Vector<T>();

        Vector<Vector<T>> vectors = Vector<Vector<T>>();
        if (this->size == 0){
            return vectors;
        }
        for (int i = 0; i < this->size; i++){
            if ( memcmp(&(vector->Get(i)), &element, sizeof(element)) == 0){
                if (timeVec.GetLenth() > 0){
                    vectors.Append(timeVec);
                }
                timeVec = Vector<T>();
            } else {
                //cout << vector->Get(i) << endl;
                timeVec.Append(vector->Get(i));
            }
        }
        if (memcmp(&(vector->Get(size - 1)), &element, sizeof(element)) != 0){
            vectors.Append(timeVec);
        }


        return vectors;
    }
};


template <typename T>
Vector<T> operator - (Vector<T> vec1, Vector<T> vec2){
    if (vec1.GetLenth() == vec2.GetLenth()){
        Vector<T> EndVector = Vector<T>();
        for (int i = 0; i < vec1.GetLenth(); i++){
            EndVector.Append(vec1[i] - vec2[i]);
        }
        return EndVector;
    } else{
        throw "Different sizes of vectors";

    }
}

template <typename T>
Vector<T> operator + (Vector<T> vec1, Vector<T> vec2){
    if (vec1.GetLenth() == vec2.GetLenth()){
        Vector<T> EndVector = Vector<T>();
        for (int i = 0; i < vec1.GetLenth(); i++){
            EndVector.Append(vec1[i] + vec2[i]);
        }
        return EndVector;
    } else{
        throw "Different sizes of vectors";

    }
}

template <typename T>
T operator * (Vector<T> vec1, Vector<T> vec2){
    if (vec1.GetLenth() == 0 || vec2.GetLenth() == 0){
        throw "Null size of vector";
    }
    T value = vec1[0] * vec2[0];
    if (vec1.GetLenth() == vec2.GetLenth()){
        for (int i = 1; i < vec1.GetLenth(); i++){
            value = (value + (vec1[i] * vec2[i]));
        }
        return value;
    } else{
        throw "Different sizes of vectors";
    }
}

template <typename T>
std::ostream& operator << (std::ostream &out, Vector<T> &vec)
{
    if (vec.GetLenth() == 0){
        out << "{}";
        return out;
    }
    out << "{";
    for (int i = 0; i < vec.GetLenth() - 1; i++){
        out << vec[i] << ", ";
    }
    if (vec.GetLenth() > 0){
        out << vec[vec.GetLenth() - 1];
    }
    out << "}";
    return out;
}





#endif //LAB2_VECTOR_H
