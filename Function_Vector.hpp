#include <iostream>
#include <initializer_list>
#include <exception>

template<typename T>
Vector<T>::Vector() {
    m_capacity = 1;
    m_size = 0;
    m_vector = new T[m_capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    if (!m_vector) {
        m_vector = new T[m_capacity];
    }
    for (int i = 0; i < m_size; ++i) {
        m_vector[i] = other.m_vector[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector<T>&& rhs) {
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_vector = rhs.m_vector;
    delete[] rhs.m_vector;
    rhs.m_vector = nullptr;
}

template<typename T>
Vector<T>::Vector(const std::initializer_list<T>& init) {
    m_capacity = init.size();
    m_size = init.size();
    m_vector = new T[m_capacity];
    int i = 0;
    for (auto it = init.begin(); it != init.end(); ++it) {
        m_vector[i++] = *it;
    }
}

template<typename T>
Vector<T>::~Vector() {
    if (m_vector) {
        delete m_vector;
        m_vector = nullptr;
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        if (!m_vector) {
            m_vector = new T[m_capacity];
        }
        for (int i = 0; i < m_size; ++i) {
            m_vector[i] = other.m_vector[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs) {
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_vector = rhs.m_vector;
    delete[] rhs.m_vector;
    rhs.m_vector = nullptr;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(Vector<T>& Vector1) {
    int count_of_elem = 0;
    if (0 == m_size) {
        for (int  i = 0; i < Vector1.m_size; ++i) {
            this->push_back(Vector1.m_vector[i]);
        }
    }
    else if (m_size < Vector1.m_size) {
        for (int i = 0; i < m_size; ++i) {
            m_vector[i] += Vector1.m_vector[i];
            ++count_of_elem;
        }
        while (count_of_elem < Vector1.m_size) {
            this->push_back(Vector1.m_vector[count_of_elem]);
            ++count_of_elem;
        }
    }
    else {
        for (int i = 0; i < Vector1.m_size; ++i) {
            m_vector[i] += Vector1.m_vector[i];
        }
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return m_vector[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return m_vector[index];
}

template<typename T>
int Vector<T>::size() {
    return m_size;
}

template<typename T>
int Vector<T>::capacity() {
    return m_capacity;
}

template<typename T>
void Vector<T>::resize() {
    if (m_capacity == m_size) {
        m_capacity *= 2;
        T* new_vector = new T[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            new_vector[i] = m_vector[i];
        }

        delete[] m_vector;
        m_vector = nullptr;
        m_vector = new_vector;
        new_vector = nullptr;
    }
}
 
template<typename T>
void Vector<T>::push_back(T value) {
    resize();
    m_vector[m_size++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    T* new_vector = new T[m_capacity];
    for (int i = 0; i < m_size - 1; ++i) {
        new_vector[i] = m_vector[i];
    }

    --m_size;
    delete[] m_vector;
    m_vector = new_vector;
    new_vector = nullptr;
}

template<typename T>
bool Vector<T>::empty() {
    if (0 == m_size) {
        return true;
    }
    return false;
}

template<typename T>
T Vector<T>::at(size_t index) {
    if (empty() || index < 0 || index >= size()) {
        throw std::out_of_range("segmentation fault");
    }
    return m_vector[index];
}

template<typename T>
T Vector<T>::front() {
    if (empty()) {
        throw std::out_of_range("segmentation fault");    
    }
    return m_vector[0];
}

template<typename T>
T Vector<T>::back() {
    if (empty()) {
        throw std::out_of_range("segmentation fault");
    }
    return m_vector[m_size - 1];
}

template<typename T>
void Vector<T>::insert(size_t index, T value) {
    if (index < 0) {
        throw std::out_of_range("segmentation fault");
    }
    else if (index > size()) {
        throw std::out_of_range("segmentation fault");
    }

    T* new_vector = new T[m_size + 1];
    int index_of_elem = 0;
    for (int i = 0; i < m_size + 1; ++i) {
        if (index == i) {
            new_vector[i] = value;
            ++index_of_elem;
        }
        new_vector[index_of_elem] = m_vector[i];
        ++index_of_elem;
    }

    ++m_size;
    resize();
    delete[] m_vector;
    m_vector = new_vector;
    new_vector = nullptr;
} 

template<typename T>
void Vector<T>::erase(size_t index) {
    if (empty()) {
        throw std::out_of_range("segmentation fault");
    }
    if (index < 0) {
        throw std::out_of_range("segmentation fault");
    }
    else if (index >= size()) {
        throw std::out_of_range("segmentation fault");
    }

    T* new_vector = new T[m_size];
    int index_of_elem = 0;
    for (int i = 0; i < m_size; ++i) {
        if (i == index) {
            continue;
        }
        new_vector[index_of_elem] = m_vector[i];
        ++index_of_elem;
    }

    --m_size;
    delete[] m_vector;
    m_vector = new_vector;
}

template<typename T>
int Vector<T>::reserve(size_t count) {
    if (count < 0) {
        throw std::out_of_range("segmentation fault");
    } 
    return m_capacity = count;
}

template<typename T>
int Vector<T>::shrink_to_fit() {    
   return m_capacity = m_size;
}

template <typename T>
template <typename... Ts>
void Vector<T>::emplace (size_t index, Ts&&... values) {
    this->insert(index,T((std::forward<Ts>(values),...)));
}