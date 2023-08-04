#include <iostream>
#include <string>

class Entity
{
    private:
        std::string m_Name;
        mutable int m_DebugCount = 0; // the mutable keyword allows the const GetName function to change
    public:
        const std::string& GetName() const // the second const means we can't reassign m_Name
        {
            m_DebugCount++;
            return m_Name;
        }
};

int main()
{
    const Entity e;
    e.GetName();

    std::cin.get();
}