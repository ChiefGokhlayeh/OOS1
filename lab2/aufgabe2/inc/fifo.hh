#ifndef FIFO_HH_
#define FIFO_HH_

template <typename T>
class Fifo
{
  public:
    Fifo(int capacity = 20)
    {
        this->capacity = capacity;
        buffer = new T[capacity];
        writePos = 0;
        readPos = 0;
        elemCount = 0;
    }

    ~Fifo()
    {
        delete[] buffer;
    }

    int GetWritePos() const
    {
        return writePos;
    }

    int GetReadPos() const
    {
        return readPos;
    }

    bool IsEmpty() const
    {
        return elemCount == 0;
    }

    bool IsFull() const
    {
        return elemCount == capacity;
    }

    int Push(T data)
    {
        if (elemCount < capacity)
        {
            buffer[writePos] = data;
            elemCount++;
            int oldWritePos = writePos;
            writePos = (writePos + 1) % capacity;
            return oldWritePos;
        }
        else
        {
            return -1;
        }
    }

    int Pop(T *data)
    {
        if (elemCount > 0)
        {
            *data = buffer[readPos];
            int oldReadPos = readPos;
            elemCount--;
            readPos = (readPos + 1) % capacity;
            return oldReadPos;
        }
        else
        {
            return -1;
        }

    }
  private:
    int capacity;
    int elemCount;
    T *buffer;
    int writePos;
    int readPos;
};

#endif
