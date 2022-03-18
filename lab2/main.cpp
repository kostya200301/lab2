#include <iostream>

//Реализовать два чернух класса
//Можно замутить конверсии одного типа в другой
//Создать абстрактный класс sequance и от него два наследника


//аппендить и увеличивать размер в динамикэррее нельзя!! Это делать в сиквенсе


using namespace std;

template <class T> class DynamicArray{
public:
    DynamicArray(int size){
        Array = new T[size];
        Size = size;
    }

    DynamicArray(T* items, int count){
        Array = new T[count];
        Size = count;
        for (int i = 0; i < Size; i++){
            *(Array + i) = *(items + i);
        }
    }

    DynamicArray(const DynamicArray<T> & dynamicArray){
        Array = new T[dynamicArray.Size];
        Size = dynamicArray.Size;
        for (int i = 0; i < Size; i++){
            *(Array + i) = *(dynamicArray.Array + i);
        }
    }

    int GetSize(){
        return Size;
    }
    void Set(int index, T value){
        *(Array + index) = value;
    }
    T Get(int index){
        return *(Array + index);
    }

    void Resize(int newSize){
        if (newSize > Size){
            T* pointer = Array;
            Array = new T[Size];
            for (int i = 0; i < Size; i++){
                *(Array + i) = *(pointer + i);
            }
            Size = newSize;
            delete[] pointer;
        } else{
            Size = newSize;
        }
    }
private:
    int Size;
    T* Array;
};


//template <class T> class LinkedList{
//public:
//    LinkedList (){
//        startIndex = 0;
//        endIndex = 0;
//    }
//    void Append(T item){
//        if (endIndex == 0){
//            Head = new list;
//            Head.element = item;
//            Head.ptr = NULL;
//        } else{
//            list *temp, *p;
//            temp = new list;
//            p = lst->ptr; // сохранение указателя на следующий узел
//            lst->ptr = temp; // предыдущий узел указывает на создаваемый
//            temp->field = number; // сохранение поля данных добавляемого узла
//            temp->ptr = p; // созданный узел указывает на следующий элемент
//            return(temp);
//        }
//    }
//
//private:
//    struct list
//    {
//        T element; // поле данных
//        struct list *ptr; // указатель на следующий элемент
//    };
//    list Head;
//    int startIndex;
//    int endIndex;
//};

template <class T> class Node
{
    T field;
    class Node *ptr;
    template<class U> friend class LinkedList;
};
template <class T> class LinkedList
{
    Node<T> *head;    // Корень списка
    int count = 0; // Количество узлов списка
    Node<T>* Prev(Node<T>* node) // Переход к предыдущему узлу (не интерфейсный метод)
    {
        if (isEmpty()) return NULL;
        if (node == head) return NULL;
        Node<T> *p = head;
        while (p->ptr != node)
            p = p->ptr;
        return p;
    }

    Node<T>* GetNodeByIndex(int index){
        if (index >= count){
            return NULL;
        }
        Node<T>* ptr = head;
        while (index > 0){
            ptr = Next(ptr);
            index--;
        }
        return ptr;
    }
public:
    LinkedList() { head = NULL; } // Инициализация списка
    int getCount() { return count; } // Получение количества узлов списка
    bool isEmpty() { return head == NULL; }  // Проверка, пуст ли список
    T getValue(Node<T>* p) { return p->field; } // Получение значения узла списка
    void setValue(Node<T> *p, T val) { p->field = val; } // Установка значения узла списка
    //void InsertAt(int item, int index);
    Node<T>* getFirst() { return head; } // Получение корневого узла списка
    //Node<T>* getLast();      // Получение последнего узла списка
    //void Clear();        // Очистка списка
    //Node<T>* Next(Node<T> *);      // Переход к следующему узлу
    //Node<T>* Add(int, Node<T>*);    // Добавление узла списка
    //Node<T>* Delete(int);    // Удаление узла списка
    //void Print();        // Вывод значений узлов списка
    //void Swap(int, int);  // Взаимообмен двух узлов

    void InsertAt(T item, int index){
        if (index == 0){
            Add(item, NULL);
        } else{
            Add(item, GetNodeByIndex(index - 1));
        }
    }

    Node<T>* Add(T num, Node<T>* node = NULL)
    {
        Node<T> *elem = new Node<T>();
        elem->field = num;
        count++;
        if (node == NULL) // Добавление нового корня
        {
            if (head == NULL) {
                elem->ptr = NULL;
                head = elem;
            }
            else {
                elem->ptr = head;
                head = elem;
            }
            return elem;
        }
        elem->ptr = node->ptr; // Добавление узла после текущего
        node->ptr = elem;
        return elem;
    }

    Node<T>* Delete(int index)
    {

        Node<T>* node = GetNodeByIndex(index);
        if (node == NULL) { return NULL; } // В списке нет узлов
        count--;
        if (node == head)  // Удаление корневого узла
        {
            head = node->ptr;
            delete node;
            return head;
        }
        Node<T>* prev = Prev(node); // Удаление промежуточного узла
        prev->ptr = node->ptr;
        delete node;
        return prev;
    }

    Node<T>* Next(Node<T>* node)
    {
        if (isEmpty()) return NULL;
        return node->ptr;
    }

    Node<T>* getLast()
    {
        Node<T>* p = head;
        while (Next(p) != NULL)
            p = Next(p);
        return p;
    }

    void Clear()
    {
        class Node<T> *p = head;
        if (p == NULL) return;
        do {
            Node<T> *d = p;
            p = Next(p);
            delete d;
        } while (p != NULL);
        count = 0;
        head = NULL;
    }

    void Print()
    {
        if (isEmpty()) { cout << "Array is empty" << endl; return; }
        Node<T> *p = head;
        do {
            cout << getValue(p) << " ";
            p = Next(p);
        } while (p != NULL);
        cout << endl;
    }

    void Swap(int first, int second)
    {
        Node<T>* node1 = GetNodeByIndex(first);
        Node<T>* node2 = GetNodeByIndex(second);
        if (node1 == NULL || node2 == NULL) return; // не допускаем обмен с несуществующим узлом
        if (node1 == node2) return; // если один узел указан дважды, менять ничего не надо
        if (node2->ptr == node1) // если node2 находится перед node1, меняем их местами
        {
            Node<T> *p = node1;
            node1 = node2;
            node2 = p;
        }
        Node<T> *prev1 = Prev(node1);
        Node<T> *prev2 = Prev(node2);
        Node<T> *next1 = Next(node1);
        Node<T> *next2 = Next(node2);
        if (next1 == node2) // обмен соседних узлов
        {
            if (prev1 != NULL)
                prev1->ptr = node2;
            else
                head = node2;
            node2->ptr = node1;
            node1->ptr = next2;
            return;
        }
        if (prev1 != NULL)  // обмен отстоящих узлов
            prev1->ptr = node2;
        else
            head = node2;
        if (prev2 != NULL)
            prev2->ptr = node1;
        else
            head = node1;
        node2->ptr = next1;
        node1->ptr = next2;
    }
};












template <class T> class Sequence{
private:
    T Array;
};

template <class T> class ArraySequence : Sequence<T>{
private:
    DynamicArray<T>* buffer;
    size_t count;
public:
    ArraySequence(T* items, size_t Count){
        buffer = DynamicArray<T>(items, count);
        count = Count;
    }

    ArraySequence(){
        buffer = new DynamicArray<T>(0);
        count = 0; //Определиться с размерами
    }

    ArraySequence (const LinkedList <T> & list){
        buffer = DynamicArray<T>(list);
        count = buffer->GetSize();
    }

    T GetFirst(){
        return buffer->Get(0);
    }

    T GetLast(){
        return buffer->Get(count);
    }

    T Get(int index){
        return buffer->Get(index);
    }

    //Sequence<T>* GetSubsequence(int startIndex, int endIndex);

    int GetLength(){
        return count;
    }

    void Append(T item){
        if (buffer->GetSize() > count){
            buffer->Set(count++, item);
        } else{
            buffer->Resize(buffer->GetSize() * 2);
            buffer->Set(count++, item);
        }
    }

    void Prepend(T item){
        if (buffer->GetSize() <= count) {
            buffer->Resize(buffer->GetSize() * 2);
        }
        for (int i = count - 1; i >= 0; i--){
            buffer->Set(i + 1, buffer->Get(i));
        }
        buffer->Set(0, item);
        count++;
    }

    void InsertAt(T item, int index){
        if (buffer->GetSize() <= count) {
            buffer->Resize(buffer->GetSize() * 2);
        }
        for (int i = count - 1; i >= index; i--){
            buffer->Set(i + 1, buffer->Get(i));
        }
        buffer->Set(index, item);
        count++;

    }

    void PrintArray(){
        for (int i = 0; i < count; i++){
            cout << buffer->Get(i) << " ";
        }
        cout << endl;
    }

    //Sequence<T>* Concat(Sequence <T> *list){}

};

template <class T> class LinkedListSequence : Sequence<T>{

};




















int main() {


    ArraySequence<int> arr = ArraySequence<int>();
    arr.Append(1);
    arr.Append(2);
    arr.Append(3);
    arr.PrintArray();
    arr.Prepend(12);
    arr.PrintArray();
    arr.InsertAt(123, 2);
    arr.PrintArray();


    return 0;
}
