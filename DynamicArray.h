#include<iostream>
#include<fstream>
#include<sstring>
#include<stdexcept>

template<typename T>
class DynamicArray
{
    private:
    T* data;
    int currentSize;
    int currentCapacity;
  
    void grow()
    {
        int newCapacity=currentCapacity*2;
        T* newData = new T[newCapacity];
        for(int i=0;i<currentSize;i++)
        {
            newData[i]=data[i];

        }
        delete[]data;
        data=newData;
        currentCapacity=newCapacity;

    }
   
    public:
    DynamicArray(int capacity=4)
    {
        if (capacity<1)
        capacity=4;

        currentCapacity=capacity;
        currentSize=0;

        data=new T[currentCapacity];

    }

    DynamicArray(const DynamicArray<T>&other)
    {
        currentSize=other.currentSize;
        currentCapacity=other.currentCapacity;

        data=new T[currentCapacity];
        for(int i=0;i<currentSize;i++)
        {
            data[i]=other.data[i];
        }
    }

    DynamicArray<T>&operator=(const DynamicArray<T>&other)
    {
        if(this!=other)
        {
            T*newData=new T[other.currentCapacity];

            for(int i=0;i<other.currentSize;i++)
            {
                newData[i]=other.data[i];
            }
            delete[]data;
            data=newData;
            currentSize=other.currentSize;
            curentCapacity=other.currentCapacity;
        }
        return*this;
        }
        ~DynamicArray()
        {
            delete[]data;
        }
        bool add(const T&item)
        {
            if(findIndex(item)!=-1)
            return false;

            if(currentSize==currentCapacity)
            {
                grow();
            }
data[currentSize]=item;
currentSize++;
return true;
    
        }
        T get(int index)const
        {
            if(index<0||index>=currentSize)
            throw std::out_of_range("Invalid array index");

            return data[index];
        }
        T&operator[](int index)
        {
            if(index<0||index>=currentSize)
            throw std::out_of_range("Invalid array index");
            return data[index];
        }
        const T&operator[](int index)const
        {
            if(index<0||index>=currentSize)
            throw std::out_of_range("Invalid array index");
            return data[index];
        }
        bool updateAt(int index, const T&item)
        {
            if(index<0||index>=currentSize)
            return false;

            for(int i=0;i<currentSize;i++)
            {
                if(i!=index&&data[i]==item)
                return false;
            }
            data[index]=item;
            return true;
        }

        int findindex(const T&item)const
        {
            for(int i=0;i<currentSize;i++)
            {
                if(data[i]==item)
                return i;
            }
            return -1;
        }
        bool removeAt(int index)
        {
            if(index<0||index>=currentSize)
            return false;

            for(int i=index;i<currentSize-1;i++)
            {
                data[i]=data[i+1];

            }
            currentSize--;

            return true;
        }

        int size() const
        {
            return currentSize;
        }
        int capacity()const
        {
            return currentCapacity;
        }
        bool isEmpty() const
        {
            return currentSize==0;
        }
        void clear()
        {
            currentSize=0;
        }

        void display()const
        {
            if(isEmpty())
            {
                std::cout<<"No student records available.\n";
                return;
            }

            for(int i=0;i<currentSize;i++)
            {
                std::cout<<data[i]<<'\n';
            }
        }
        bool saveToFile(const std::string&filename)const
        {
            std::ofstream file(filename);
           
            if(!file.is_open())
            return false;

            for(int i=0;i<currentSize;i++)
            {
                file<<data[i]<<'\n';
            }

            return file.good();
        }
        bool loadFromFile(const std::string&filename)
        {
            std::ifstream file(filename);

            if(!file.is_open())
            return false;

            DynamicArray<T>temporary;

            std::string line;
            while(std::getline(file,line))
            {
                if(line.empty())
                continue;

                std::istringstream recordStream(line);
                T item;

                if(!(recordStream>>item))
                return false;

                if(!temporary.add(item))
                return false;
            }
            if(file.bad())
            return false;

            *this=temporary;

            return true;
        }
    };