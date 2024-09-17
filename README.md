# Strings
This repository describes the theory behind string data structures, as well as the various methods applied to them.

Definition: In computer science, a **string** is a sequence of characters used to represent text. Characters can include letters, numbers, symbols, and even whitespace (such as spaces or tabs). Strings are a fundamental data type in most programming languages and are typically used for storing and manipulating text-based data.

## String representation

In C++ there are two ways of declaring strings:

#### 1. With arrays

The code below describes different ways of declaring and initializing a string using arrays.

```cpp
#include <iostream>

using namespace std;

int main()
{
    char string1[10] = {'H', 'e', 'l', 'l', 'o', '\0'}; //declare and initializing an array of characters with the size 10
    char string2[] = {'H', 'e', 'l', 'l', 'o', '\0'}; //declare and initializing an array of characters without mentioning the size
    char string3[] = {65, 66, 67, 68 , 69}; //declare and initializing an array of characters using ASCII code
    char string4[] = "Hello"; //declare and initializing an array of characters using double quotes
    char* string5 = new char[10]; //declare a constant pointer to the first character of a string
    const char* string6 = "Hello";  
    return 0;
}
```

#### 2. With string library

The code below describe the way of declaration and initalization of a string using string library.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string string1; //declare an object(string1) of class string
    string1 = "Hello"; //initialize this string object with the string of characters "Hello"
    return 0;
}
```

## Important notes on strings

- A string is essentially an array or list of characters arranged in a specific order.
- In C++ the string must be terminated with the null character, otherwise that array is just an array of characters if you use the __array method__ of representing the string, but if you use the __string library method__ the compiler will take care of the null character itself.
- Usually each character of a string uses the ASCII code for English language, and those are represented in the memory of the computer by one byte.

## String operations

This section aims to describe in detail the operations that can be performed on a string for the user to understand them better, although these methods are already provided in the standard libraries of programming languages.

I will assume that for the following operations will use the next class:

```cpp
#include <iostream>

using namespace std;

class String
{
private:
    char* myString;
    int length;
    int size;

public:
    String()
    {
        size = 10;
        length = 0;
        myString = new char[size];
    }

    String(int size)
    {
        this->size = size;
        length = 0;
        myString = new char[size];
    }

    ~String()
    {
        delete []myString;
    }

    void append(char character)
    {
        if(length >= 0 && length < size)
        {
            myString[length] = character;
            if(character != '\0')
                length++;
        }
    }

    void display()
    {
        if(length >= 0 && length < size)
        {
            cout << "The string is: ";
            for(int i = 0; i < length; i++)
            {
                cout << myString[i];
            }
            cout << endl;
        }
    }
};
```

And the main function is:

```cpp
int main()
{
    String* theString = new String(10);

    theString->append('H');
    theString->append('e');
    theString->append('l');
    theString->append('l');
    theString->append('o');
    theString->append('\0');

    return 0;
}
```

### 1. **Length** of a string

This function will return the length of a string, that is the number of characters present in a string.

It has a time complexity of:
- **Ω(1)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
int lengthOfString()
{
    int count = 0;

    for(count = 0; myString[count] != '\0'; count++){}

    this->length = count;
    return count;
}
```

### 2. Switch **case**

This function will change the characters of a string for lowercase to uppercase and vice versa.

It has a time complexity of:
- **Ω(n)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
int lengthOfString()
{
    int count = 0;

    for(count = 0; myString[count] != '\0'; count++){}

    this->length = count;
    return count;
}
```

### 3. **Vowels**

This function will return the numbers of vowels presents in a string.

It has a time complexity of:
- **Ω(n)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
int vowels()
{
    if(length >= 0 && length < size)
    {
        int count = 0;
        for(int i = 0; i < length; i++)
        {
            if((myString[i] >= 65 && myString[i] <= 90) || (myString[i] >= 97 && myString[i] <= 122))
                if(myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' || myString[i] == 'o' || myString[i] == 'u' ||
                    myString[i] == 'A' || myString[i] == 'E' || myString[i] == 'I' || myString[i] == 'O' || myString[i] == 'U')
                    count++;
        }
        return count;
    }
    return 0;
}
```

### 4. **Consonents**

This function will return the numbers of consonents presents in a string.

It has a time complexity of:
- **Ω(n)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
int consonents()
{
    if(length >= 0 && length < size)
    {
        int count = 0;
        for(int i = 0; i < length; i++)
        {
            if((myString[i] >= 65 && myString[i] <= 90) || (myString[i] >= 97 && myString[i] <= 122))
                if(myString[i] != 'a' && myString[i] != 'e' && myString[i] != 'i' && myString[i] != 'o' && myString[i] != 'u' &&
                    myString[i] != 'A' && myString[i] != 'E' && myString[i] != 'I' && myString[i] != 'O' && myString[i] != 'U')
                    count++;
        }
        return count;
    }
    return 0;
}
```

### 5. **Words**

This function will return the numbers of words presents in a string.

It has a time complexity of:
- **Ω(n)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
int words()
{
    if(length >= 0 && length < size)
    {
        int count = 1;
        for(int i = 0; i < length; i++)
        {
            if(myString[i] == ' ' && myString[i - 1] != ' ')
                count++;
        }
        return count;
    }
    return 0;
}
```

### 6. **Reverse**

This function will reverse a string.

It has a time complexity of:
- **Ω(n)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
template <class T>
void swap(T* first, T* second)
{
    T temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void reverse()
{
    if(length >= 0 && length < size)
    {
        int i = 0;
        int j = length - 1;

        while(i < j)
        {
            swap(&myString[i], &myString[j]);
            i++;
            j--;
        }
    }
}
```

### 7. **Compare**

This function will compare two strings to check if they are identical.

It has a time complexity of:
- **Ω(1)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
bool compare(char* otherString)
{
    if(length >=0 && length < size)
    {
        for(int i = 0, j = 0; myString[i] == otherString[j]; i++, j++)
        {
            if(myString[i] == '\0' && otherString[j] == '\0')
                return true;
        }
        return false;
    }

    return false;
}
```

### 8. **Palindrome**

This function will check if a string is a palidrome.

It has a time complexity of:
- **Ω(n)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
bool palidrome()
{
    if(length >= 0 && length < size)
    {
        int i = 0;
        int j = length - 1;

        while(i < j)
        {
            if(myString[i] != myString[j])
                return false;
            else
            {
                i++, j--;
            }
        }
        return true;
    }
    return false;
}
```

### 9. **Duplicates**

This function will check if there is duplicates in a string.

It has a time complexity of:
- **Ω(n)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
void duplicates()
{
    if(length >= 0 && length < size)
    {

        int* hashTable = new int[58]{0};

        for(int i = 0; myString[i] != '\0'; i++)
        {
            hashTable[myString[i] - 65]++;
        }

        for(int i = 0; hashTable[i] < 58; i++)
        {
            if(hashTable[i] > 1)
                printf("The element %c has %d duplicates.\n", (i + 65), hashTable[i]);
        }
    }
}
```

### 10. **Anagram**

This function will check if a given string is an anagram.

It has a time complexity of:
- **Ω(n)** for best case
- **θ(n)** for average case
- **O(n)** for worst case

```cpp
bool anagram(char* secondString)
{
    if(length >= 0 && length < size)
    {
        int* hashTable = new int[26]{0};

        for(int i = 0; myString[i] != '\0'; i++)
        {
            if((myString[i] >= 65 && myString[i] <= 90))
                myString[i] += 32;

            hashTable[myString[i] - 97]++;
        }

        for(int i = 0; secondString[i] != '\0'; i++)
        {
            if((secondString[i] >= 65 && secondString[i] <= 90))
                secondString[i] += 32;

            hashTable[secondString[i] - 97]--;
        }

        for(int i = 0; i < 26; i++)
        {
            if(hashTable[i] < 0)
                return false;
        }

        return true;

    }
    return false;
}
```

