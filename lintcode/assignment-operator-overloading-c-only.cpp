/**
*Implement an assignment operator overloading method.
*Example*
*If we assign like *A = B*, the data in A should be deleted, and A can have a copy of data from B.
If we assign like *A = B = C*, both A and B should have a copy of data from C.*

*Challenge*
*Consider about the safety issue if you can and make sure you released the old data.*

*Clarification*
*This problem is for *C++* only as *Java* and *Python* don't have overloading for assignment operator.*
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (this != &object) {
            // 1: Allocate new memory and copy the elements.
            char *new_pData = nullptr;
            if (object.m_pData != nullptr) {
                size_t count = strlen(object.m_pData);
                new_pData = new char[count];
                copy(object.m_pData, object.m_pData + count, new_pData);
            }

            // 2: Deallocate old memory.
            if (m_pData != nullptr) {
                delete[] m_pData;
            }

            // 3: Assign the new memory to the object.
            m_pData = new_pData;;
        }
        return *this;
    }
};
