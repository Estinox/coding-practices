#include <iostream>

using namespace std;

class Message
{
    public:
        std::string getHeader (const std::string& header_name) const;
        // other methods...
};
 
class MessageSorter
{
    public:
        // take the field to sort by in the constructor
        MessageSorter (const std::string& field) : _field( field ) {}
        bool operator() (const Message& lhs, const Message& rhs)
        {
            // get the field to sort by and make the comparison
            return lhs.getHeader( _field ) < rhs.getHeader( _field );
        }
    private:
        std::string _field;
};

int main ()
{
  
}
