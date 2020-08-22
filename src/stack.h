#ifndef STACK_H_
#define STACK_H_

#include <stdexcept>

template <typename TYPE>
    class Stack {
        public:
            explicit Stack(size_t size_max) :
                m_size_max(size_max), m_size(0)
            {
                m_array = new TYPE[size_max];
            }

            virtual ~Stack() {
                delete[] m_array;
            }
        public:
            void push(const TYPE& value) {
                check_overflow();
                m_array[m_size] = value;
                ++m_size;
            }

            void pop() {
                check_overflow();
                --m_size;
            }

        private:
            const TYPE& top_() const {
                check_overflow();
                return m_array[m_size -1];
            }

        public:
            TYPE&       top()       { return const_cast<TYPE&>(top_()); }
            const TYPE& top() const { return top_(); }

            bool full() const { return m_size == m_size_max; }

            bool empty() const { return m_size == 0; }

        private:
            void check_overflow() const {
                if(full()) {
                    throw std::overflow_error("stack overflow");
                }
            }

            void check_underflow() const {
                if(empty()) {
                    throw std::underflow_error("stack is empty");
                }
            }

        private:
            TYPE* m_array;
            size_t m_size_max;
            size_t m_size;
    };

#endif
