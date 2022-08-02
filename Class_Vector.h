#ifndef CLASS_VECTOR
#define CLASS_VECTOR

template<typename T>
class Vector
{
public:
    Vector(); // default constructor
    Vector(const Vector&); // copy constructor
    Vector(Vector&&); // move constructor
    Vector(const std::initializer_list<T>&); // initialized constructor
    ~Vector(); // destructor 

public:
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);
    T& operator[](size_t);
    const T& operator[](size_t) const;
    Vector<T>& operator+=(Vector<T>&);

    friend std::ostream& operator<<(std::ostream& stream, const Vector<T>& vec) {
        for (int i = 0; i < vec.m_size; ++i) {
            stream << vec.m_vector[i] << " ";
        }
        return stream;
    }

    friend bool operator==(const Vector<T>& Vector1, const Vector<T>& Vector2) {
        if (Vector1.m_size != Vector2.m_size) {
            return false;
        } else {
            for (int i = 0; i < Vector1.m_size; ++i) {
                if (Vector1.m_vector[i] != Vector2.m_vector[i]) {
                    return false;
                } 
            }
            return true;
        }
    }

    friend bool operator!=(const Vector<T>& Vector1, const Vector<T>& Vector2) {
        return !(Vector1 == Vector2);
    }

    friend bool operator<(const Vector<T>& Vector1, const Vector<T>& Vector2) {
        if (Vector1.m_size != Vector2.m_size) {
            return false;
        }
        for (int i = 0; i < Vector1.m_size; ++i) {
            if (Vector1.m_vector[i] >= Vector2.m_vector[i]) {
                return false;
            }
        }
        return true;
    }

    friend bool operator>(const Vector<T> Vector1, const Vector<T>& Vector2) {
        return !(Vector1 < Vector2);
    }

    friend bool operator<=(const Vector<T> Vector1, const Vector<T>& Vector2) {
        return (Vector1 < Vector2 || Vector1 == Vector2);
    }

    friend bool operator>=(const Vector<T> Vector1, const Vector<T>& Vector2) {
        return (Vector1 > Vector2 || Vector1 == Vector2);
    }

    friend Vector<T> operator+(Vector<T>& Vector1, Vector<T>& Vector2) {
        Vector<T> new_vector;
        int size = Vector2.m_size;
        if (Vector1.m_size > Vector2.m_size) {
            size = Vector1.m_size;
            for (int i = 0; i < size; ++i) {
                while (i < Vector2.m_size) {
                    T element = Vector1[i] + Vector2[i];
                    new_vector.push_back (element);
                    ++i;
                }
                new_vector.push_back(Vector1[i]);
            }
        }
        else if (Vector1.m_size < Vector2.m_size) {
            for (int i = 0; i < size; ++i) {
                while (i < Vector1.m_size) {
                    T element = Vector1[i] + Vector2[i];
                    new_vector.push_back (element);
                    ++i;
                }
                new_vector.push_back(Vector2[i]);
            }
        }
        else {
            for (int i = 0; i < size; ++i) {
                T element = Vector1[i] + Vector2[i];
                new_vector.push_back (element);
            }
        }
        return new_vector;
    }

public:
    T at(size_t); 
    T front(); 
    T back();
    bool empty(); 
    int size(); 
    int capacity();
    int reserve(size_t); 
    int shrink_to_fit(); 
    void insert(size_t, T); 
    void push_back(T); 
    void pop_back(); 
    void resize(); 
    void erase(size_t); 
    template <typename... Ts>
    void emplace(size_t, Ts&&...); 

private:
    T* m_vector;
    size_t m_size;
    size_t m_capacity;
};

#include "Function_Vector.hpp"

#endif // CLASS_VECTOR