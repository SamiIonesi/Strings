#include <iostream>
#include <cstdio>

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

    int getLength() { return length;}

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

    int lengthOfString()
    {
        int count = 0;

        for(count = 0; myString[count] != '\0'; count++){}

        this->length = count;
        return count;
    }

    void changeCase()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 0; i < length; i++)
            {
                if(myString[i] >= 65 && myString[i] <= 90)
                    myString[i] += 32;
                else if(myString[i] >= 97 && myString[i] <= 122)
                    myString[i] -= 32;
            }
        }
    }

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

    void toLower()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 0; myString[i] != '\0'; i++)
            {
                if((myString[i] >= 65 && myString[i] <= 90))
                    myString[i] += 32;
            }
        }
    }

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

};

int main()
{
    String* theString = new String(20);
    char otherStr[10] = {'d', 'e', 'c', 'i', 'm', 'a', 'i', '\0'};

    theString->append('m');
    theString->append('e');
    theString->append('d');
    theString->append('i');
    theString->append('c');
    theString->append('a');
    theString->append('i');
    theString->append('\0');

    cout << theString->anagram(otherStr);

    return 0;
}




