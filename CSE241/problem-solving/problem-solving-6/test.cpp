

template <class T, class U>
class Para
{
    public:
    friend bool operator>(Para<T,U>& p1, Para<T,U>& p2)
    {
        p1.dollar > p2.dollar;

        p1.dollar *10;
        

    }
    private:
    T dollar;
    U cent;


};


class A
{


};

int main()
{

    Para<int, double> p1;
    Para<int, double> p2;
    Para<A,double> p3;
    Para<A,double> p4;

    if(p3>p4)
    {

    }

}