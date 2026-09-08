#pragma once

template <typename T>
class SharedPointer
{
public:
    SharedPointer() = default;
    SharedPointer(T *pointer) : m_pointer(pointer)
    {
        m_control = new ControlBlock(m_pointer);
    }

    SharedPointer(const SharedPointer<T> &other)
        : m_pointer(other.m_pointer), m_control(other.m_control)
    {
        (*m_control)++;
    }

    SharedPointer(SharedPointer<T> &&other) noexcept
        : m_pointer(other.m_pointer), m_control(other.m_control)
    {
        other.m_pointer = nullptr;
        other.m_control = nullptr;
    }

    ~SharedPointer()
    {
        if (m_control)
            (*m_control)--;
    }

    SharedPointer<T> &operator=(const SharedPointer<T> &other)
    {
        if (*this == other)
            return *this;

        (*m_control)--;

        this->m_pointer = other.m_pointer;
        this->m_control = other.m_control;

        (*m_control)++;
        return *this;
    }

    SharedPointer<T> &operator=(SharedPointer<T> &&other) noexcept
    {
        if (*this == other)
            return *this;

        (*m_control)--;

        this->m_pointer = other.m_pointer;
        this->m_control = other.m_control;
        other.m_pointer = nullptr;
        other.m_control = nullptr;
        return *this;
    }

    bool operator==(const SharedPointer<T> &other) const
    {
        return *(this->m_pointer) == *(other.m_pointer) && this->m_control == other.m_control;
    }

    T &operator*()
    {
        return *m_pointer;
    };

    unsigned int getCount()
    {
        if (m_control)
            return m_control->count();
        else
            return 0;
    }

    T *get()
    {
        return m_pointer;
    }

private:
    class ControlBlock
    {
    public:
        ControlBlock() = default;
        ControlBlock(T *m_pointer) : m_pointer(m_pointer)
        {
        }
        ~ControlBlock()
        {
            delete m_pointer;
        }
        unsigned int count() const
        {
            return m_count;
        }
        void operator--(int)
        {
            if (--m_count <= 0)
                delete this;
        }
        void operator++(int)
        {
            m_count++;
        }

    private:
        T *m_pointer = nullptr;
        unsigned int m_count = 1;
    };

private:
    T *m_pointer = nullptr;
    ControlBlock *m_control = nullptr;
};
