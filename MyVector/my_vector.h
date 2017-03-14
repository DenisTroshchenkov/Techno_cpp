/*!
    \file

    \brief Заголовочный файл с описание класса MyVector

    \author Трощенков Денис

    \data 27.02.2017

    Реализация динамического массива
*/

#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <new>
#include <iostream>
#include <stdexcept>
#include <caccert>

/*!
    \brief Класс MyVector
*/
namespace mcr {
template <typename T>	
class MyVector
{
public:
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference; 	
    typedef const T* const_pointer;
    typedef T* pointer;

    /*! 
        \brief  Конструктор по умолчанию. Создает пустой контейнер.        +++
  
        \param[in] Начальный размер вектора
    */
    explicit MyVector();
    /*! 
        \brief  Конструктор с одним параметром                             +++
 
        \param[in] Начальный размер вектора
   */
    explicit MyVector(size_type);
    /*! 
        \brief  Конструктор с инициализацией                               +++
  
        \param[in] Начальный размер вектора
    */
    explicit MyVector(size_type, const value_tupe&);                       
    /*! 
        \brief Копирующей конструктор                                      +++
        
        \param[in] объект типа  MyVector
        
    */				
    MyVector( const MyVector<value_type>& );
    /*! 
        \brief Конструктор с перемещением                                   +++
        
        \param[in] объект типа  MyVector
        
    */	
    MyVector( Myvector&& );	
    /*!
        \brief Деструктор                                                   +++
    */                         						
    ~MyVector();					                								
    /*!
        \brief Оператор присваивания с копированием 
    */
    MyVector& operator = (const MyVector& );
    /*!
        \brief Оператор присваивания с перемещением 
    */
    MyVector& operator = (MyVector&& );
    /*!
        \brief Предоставление доступа к указанному элементу для не константного 
               объекта
    */ 	                                                                         
    reference operator [] (size_type);
    /*!
        \brief Предоставление доступа к указанному элементу для константного 
               объекта
    */ 	                                                                         
    const_reference operator [] (size_type) const;
    /*!
        \brief Оператор сравнения  
    */		                           			       	
    bool operator == (const MyVector&, const MyVector&);                 					       	
    /*! 
        \brief Взятие произвольного элемента вектора для константного объекта                 +++
        \param[in] Индекс элемента
        
        \return Ссылка на объект
   */
    const_referens at(size_type) const;
    /*! 
        \brief Взятие произвольного элемента вектора для не константного объекта               +++
        \param[in] Индекс элемента      
        
        \return Ссылка на объект
    */		                         		
    referens at(size_type);
    /*!
        \brief Удаление верхнего элемента                                                     +++
    */				 		
    void pop_back();	
    /*!
        \brief Добавление элемента с копированием
        \param[in] Новый элемент вектора        
    */			                  							
    void push_back( const value_type& );
    /*!
        \brief Добавление элемента с перемещением
        \param[in] Новый элемент вектора        
    */	
    void push_back( T&& value );
    /*! 
        \brief Копирование содержимого 
        \param[in] объект типа  MyVector
   */	                         							
    void copy( const MyVector<value_type>& );
    /*!
        \brief   Количество элементов вектора   
        \return Размер вектора
    */	                         							
    size_type size() const;
    /*!
        \brief Проверка наличия элементов
        \return True if size > 0 else false
    */				                  						
    bool empty() const;				                          							
    /*!
        \brief Максимально допустимое количество элементов
        \return Максимальное количество элементов
    */	
    size_type max_size() const;
    /*!
        \brief Доступ к первому элементу для константного объекта
        \return Ссылка на первый элемент
    */
    const_reference front() const;
    /*!
        \brief Доступ к первому элементу для не константного объекта
        \return Ссылка на первый элемент
    */                                  
    reference front(); 
    /*!
        \brief Доступ к Верхнему элементу для константного объекта
        \return Ссылка на верхний последний элемент
    */                                            
    const_reference back() const;
    /*!
        \brief Доступ к Верхнему элементу для не константного объекта
        \return Ссылка на верхний последний элемент
    */ 		                  			
    reference back();
    /*!
        \brief Возвращает указатель на базовый массив, выступающей 
         в качестве элемента хранения для не константного объекта
    */
    pointer data();
    /*!
        \brief Возвращает указатель на базовый массив, выступающей 
         в качестве элемента хранения для константного объекта
    */
    const_pointer data() const;				                  
    /*!
        \brief Устанавливает минимально возможное количество элементов в векторе
        \param[in] Новый размер вектора
    */			
    void reserve(size_type);  
    /*!
        \brief Возвращает количество элементов, которое может содержать вектор до того, 
               как ему потребуется выделить больше места.
    */
    size_type capacity() const;
    /*!
        \brief Уменьшает количество используемой памяти за счет освобождения неиспользованной
    */
    void shrink_to_fit();
    /*!
        \brief Изменяет размер вектора на заданную величину
    */
    void resize( size_type count );
    /*!
        \brief Изменение размера вектора на заданную величину,
               с инициализацией 
    */
    void resize( size_type count, const value_type& value);
    /*!
         \brief Удаляет все элементы вектора
    */
    void clear();
    /*!
         \brief Обменять содержимое двух векторов
    */
    void swap( vector& other );                                            	
    /*!
        \brief Вывод структуру вектора на экран
    */						
    void show() const;				                          						
private:
    /// Количество элементов которые могут одновременно хранится в выделенной области памяти
    size_type m_capacity;
    /// Количество элементов                                                 								
    size_type m_size;
    /// Указатель область памяти, хранящей элементы вектора				                         					
    value_type* m_ptr;
    /*!
        \brief Верификатор 			
    */	                          							
    bool v_ok() const;
    /*!
        \brief Дампер
        
        \param[in] func_name Имя функции, которая вызвала верификатор
        \param[in] file_name Имя файла
        \param[in] line номер строки, которая вызвала верификатор
    */				                         							
    inline void stk_dump(const char*, int, const char*) const;            								
		
};
}

#include "MyVector.hpp"

#endif
